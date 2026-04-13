#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

typedef enum { TOK_NUMBER, TOK_OP, TOK_LPAREN, TOK_RPAREN, TOK_COMMA, TOK_IDENT, TOK_END } TokenType;

typedef struct {
    TokenType type;
    double value;       // for numbers
    char *text;         // for operators and identifiers
} Token;

typedef struct {
    Token *data;
    size_t size;
    size_t cap;
} TokenArray;

static void ta_init(TokenArray *a) { a->data = NULL; a->size = a->cap = 0; }
static void ta_push(TokenArray *a, Token t) {
    if (a->size == a->cap) {
        a->cap = a->cap ? a->cap * 2 : 8;
        a->data = realloc(a->data, a->cap * sizeof(Token));
    }
    a->data[a->size++] = t;
}
static void ta_free(TokenArray *a) {
    for (size_t i = 0; i < a->size; ++i) free(a->data[i].text);
    free(a->data);
    a->data = NULL; a->size = a->cap = 0;
}

typedef enum { ASSOC_LEFT, ASSOC_RIGHT } Assoc;
typedef struct { const char *op; int prec; Assoc assoc; } OpInfo;

static OpInfo ops[] = {
    {"^",  4, ASSOC_RIGHT},
    {"*",  3, ASSOC_LEFT},
    {"/",  3, ASSOC_LEFT},
    {"%",  3, ASSOC_LEFT},
    {"+",  2, ASSOC_LEFT},
    {"-",  2, ASSOC_LEFT},
    {NULL, 0, 0}
};

static const char *trim(char *s) {
    while (isspace((unsigned char)*s)) ++s;
    if (*s == 0) return s;
    char *end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) *end-- = 0;
    return s;
}

static int is_ident_char(char c) {
    return isalpha((unsigned char)c) || c == '_' || isdigit((unsigned char)c);
}

static TokenArray tokenize(const char *input) {
    TokenArray out; ta_init(&out);
    const char *p = input;
    while (*p) {
        if (isspace((unsigned char)*p)) { ++p; continue; }
        if (isdigit((unsigned char)*p) || (*p == '.' && isdigit((unsigned char)*(p+1)))) {
            char *end;
            errno = 0;
            double val = strtod(p, &end);
            if (p == end) break;
            Token t = {TOK_NUMBER, val, NULL};
            ta_push(&out, t);
            p = end;
            continue;
        }
        if (isalpha((unsigned char)*p) || *p == '_') {
            const char *st = p;
            while (is_ident_char(*p)) ++p;
            size_t len = p - st;
            char *name = malloc(len + 1);
            memcpy(name, st, len); name[len] = 0;
            Token t = {TOK_IDENT, 0, name};
            ta_push(&out, t);
            continue;
        }
        // Operators and punctuation
        if (*p == '(') { Token t = {TOK_LPAREN, 0, strdup("(")}; ta_push(&out, t); ++p; continue; }
        if (*p == ')') { Token t = {TOK_RPAREN, 0, strdup(")")}; ta_push(&out, t); ++p; continue; }
        if (*p == ',') { Token t = {TOK_COMMA, 0, strdup(",")}; ta_push(&out, t); ++p; continue; }
        // Two-char ops? none required; treat single char operators
        char buf[2] = {*p, 0};
        Token t = {TOK_OP, 0, strdup(buf)};
        ta_push(&out, t);
        ++p;
    }
    Token t = {TOK_END, 0, NULL}; ta_push(&out, t);
    return out;
}

static const OpInfo* get_op(const char *op) {
    for (OpInfo *o = ops; o->op; ++o) {
        if (strcmp(o->op, op) == 0) return o;
    }
    return NULL;
}

typedef struct {
    Token *data;
    size_t size;
    size_t cap;
} Stack;

static void st_init(Stack *s) { s->data = NULL; s->size = s->cap = 0; }
static void st_push(Stack *s, Token t) {
    if (s->size == s->cap) {
        s->cap = s->cap ? s->cap * 2 : 8;
        s->data = realloc(s->data, s->cap * sizeof(Token));
    }
    s->data[s->size++] = t;
}
static Token st_pop(Stack *s) {
    Token t = s->data[--s->size];
    return t;
}
static Token* st_peek(Stack *s) { if (s->size==0) return NULL; return &s->data[s->size-1]; }
static int st_empty(Stack *s) { return s->size == 0; }
static void st_free(Stack *s) { for (size_t i = 0; i < s->size; ++i) free(s->data[i].text); free(s->data); s->data=NULL; s->size=s->cap=0; }

typedef struct {
    Token *data;
    size_t size;
    size_t cap;
} RPN;

static void rpn_init(RPN *r) { r->data = NULL; r->size = r->cap = 0; }
static void rpn_push(RPN *r, Token t) {
    if (r->size == r->cap) {
        r->cap = r->cap ? r->cap * 2 : 8;
        r->data = realloc(r->data, r->cap * sizeof(Token));
    }
    r->data[r->size++] = t;
}
static void rpn_free(RPN *r) { for (size_t i = 0; i < r->size; ++i) free(r->data[i].text); free(r->data); r->data = NULL; r->size = r->cap = 0; }

typedef double (*fn1)(double);
typedef double (*fn2)(double,double);

typedef struct {
    const char *name;
    int arity;
    void *func;
} FuncEntry;

static double fn_pow_wrapper(double a, double b) { return pow(a,b); }

static double fn_log10_wrapper(double a) { return log10(a); }

static FuncEntry functions[] = {
    {"sin", 1, (void*)sin},
    {"cos", 1, (void*)cos},
    {"tan", 1, (void*)tan},
    {"asin",1, (void*)asin},
    {"acos",1, (void*)acos},
    {"atan",1, (void*)atan},
    {"sqrt",1, (void*)sqrt},
    {"ln",  1, (void*)log},
    {"log", 1, (void*)fn_log10_wrapper},
    {"exp", 1, (void*)exp},
    {"abs", 1, (void*)fabs},
    {"pow", 2, (void*)fn_pow_wrapper},
    {NULL, 0, NULL}
};

static FuncEntry *find_func(const char *name) {
    for (FuncEntry *f = functions; f->name; ++f) {
        if (strcmp(f->name, name) == 0) return f;
    }
    return NULL;
}

static int is_unary_minus(TokenArray *tokens, size_t idx) {
    // unary minus if token is '-' and (it's at start or previous token is operator, left paren, or comma)
    if (tokens->data[idx].type != TOK_OP) return 0;
    if (strcmp(tokens->data[idx].text, "-") != 0) return 0;
    if (idx == 0) return 1;
    TokenType prev = tokens->data[idx-1].type;
    if (prev == TOK_OP || prev == TOK_LPAREN || prev == TOK_COMMA) return 1;
    return 0;
}

// Convert tokens (infix) to RPN (shunting-yard)
static int to_rpn(TokenArray *tokens, RPN *out, char *errbuf, size_t errlen) {
    Stack opstack; st_init(&opstack);
    for (size_t i = 0; i < tokens->size; ++i) {
        Token t = tokens->data[i];
        if (t.type == TOK_NUMBER) {
            Token copy = t; copy.text = NULL; rpn_push(out, copy);
        } else if (t.type == TOK_IDENT) {
            // function or constant/variable
            FuncEntry *fe = find_func(t.text);
            if (fe) {
                Token copy = {TOK_IDENT, 0, strdup(t.text)};
                st_push(&opstack, copy); // push function name onto opstack
            } else {
                // constant name -> replace with numeric token if known
                if (strcmp(t.text, "pi") == 0) {
                    Token num = {TOK_NUMBER, M_PI, NULL}; rpn_push(out, num);
                } else if (strcmp(t.text, "e") == 0) {
                    Token num = {TOK_NUMBER, M_E, NULL}; rpn_push(out, num);
                } else {
                    // unknown identifier: treat as error
                    snprintf(errbuf, errlen, "Unknown identifier: %s", t.text);
                    st_free(&opstack);
                    return 0;
                }
            }
        } else if (t.type == TOK_COMMA) {
            // pop until left paren
            int found = 0;
            while (!st_empty(&opstack)) {
                Token *top = st_peek(&opstack);
                if (top->type == TOK_LPAREN) { found = 1; break; }
                Token popped = st_pop(&opstack);
                rpn_push(out, popped);
            }
            if (!found) {
                snprintf(errbuf, errlen, "Misplaced comma or mismatched parentheses");
                st_free(&opstack);
                return 0;
            }
        } else if (t.type == TOK_OP) {
            // handle unary minus: convert to a unary function "neg"
            if (is_unary_minus(tokens, i)) {
                Token func = {TOK_IDENT, 0, strdup("neg")};
                st_push(&opstack, func);
            } else {
                const OpInfo *o1 = get_op(t.text);
                if (!o1) {
                    snprintf(errbuf, errlen, "Unknown operator: %s", t.text);
                    st_free(&opstack);
                    return 0;
                }
                while (!st_empty(&opstack)) {
                    Token *top = st_peek(&opstack);
                    if (top->type == TOK_OP) {
                        const OpInfo *o2 = get_op(top->text);
                        if (!o2) break;
                        if ((o1->assoc == ASSOC_LEFT && o1->prec <= o2->prec) ||
                            (o1->assoc == ASSOC_RIGHT && o1->prec < o2->prec)) {
                            Token popped = st_pop(&opstack);
                            rpn_push(out, popped);
                            continue;
                        }
                    } else if (top->type == TOK_IDENT) {
                        // function on top should not be popped here (only on closing paren)
                    }
                    break;
                }
                Token copy = {TOK_OP, 0, strdup(t.text)};
                st_push(&opstack, copy);
            }
        } else if (t.type == TOK_LPAREN) {
            Token copy = {TOK_LPAREN, 0, strdup("(")};
            st_push(&opstack, copy);
        } else if (t.type == TOK_RPAREN) {
            int found = 0;
            while (!st_empty(&opstack)) {
                Token top = st_pop(&opstack);
                if (top.type == TOK_LPAREN) { found = 1; free(top.text); break; }
                rpn_push(out, top);
            }
            if (!found) { snprintf(errbuf, errlen, "Mismatched parentheses"); st_free(&opstack); return 0; }
            // if top of stack is a function, pop it into output
            if (!st_empty(&opstack)) {
                Token *top = st_peek(&opstack);
                if (top->type == TOK_IDENT) {
                    Token func = st_pop(&opstack);
                    rpn_push(out, func);
                }
            }
        } else if (t.type == TOK_END) {
            break;
        }
    }
    while (!st_empty(&opstack)) {
        Token top = st_pop(&opstack);
        if (top.type == TOK_LPAREN || top.type == TOK_RPAREN) {
            snprintf(errbuf, errlen, "Mismatched parentheses");
            st_free(&opstack); return 0;
        }
        rpn_push(out, top);
    }
    st_free(&opstack);
    return 1;
}
static int evaluate_rpn(RPN *r, double *result, char *errbuf, size_t errlen, double last_result) {
    double *stack = NULL;
    size_t sz = 0, cap = 0;
    #define PUSH(v) do { if (sz==cap) { cap = cap?cap*2:16; stack = realloc(stack, cap*sizeof(double)); } stack[sz++] = (v); } while(0)
    #define POP() (sz?stack[--sz]:0)
    for (size_t i = 0; i < r->size; ++i) {
        Token t = r->data[i];
        if (t.type == TOK_NUMBER) {
            PUSH(t.value);
        } else if (t.type == TOK_OP) {
            if (sz < 2) { snprintf(errbuf, errlen, "Not enough operands for operator %s", t.text); free(stack); return 0; }
            double b = POP(); double a = POP();
            if (strcmp(t.text, "+") == 0) PUSH(a + b);
            else if (strcmp(t.text, "-") == 0) PUSH(a - b);
            else if (strcmp(t.text, "*") == 0) PUSH(a * b);
            else if (strcmp(t.text, "/") == 0) {
                if (b == 0) { snprintf(errbuf, errlen, "Division by zero"); free(stack); return 0; }
                PUSH(a / b);
            } else if (strcmp(t.text, "%") == 0) {
                if (b == 0) { snprintf(errbuf, errlen, "Modulo by zero"); free(stack); return 0; }
                PUSH(fmod(a, b));
            } else if (strcmp(t.text, "^") == 0) {
                PUSH(pow(a, b));
            } else {
                snprintf(errbuf, errlen, "Unknown operator in eval: %s", t.text);
                free(stack); return 0;
            }
        } else if (t.type == TOK_IDENT) {
            // functions: check arity
            if (strcmp(t.text, "neg") == 0) {
                if (sz < 1) { snprintf(errbuf, errlen, "Not enough operands for unary -"); free(stack); return 0; }
                double v = POP(); PUSH(-v);
            } else {
                FuncEntry *fe = find_func(t.text);
                if (!fe) { snprintf(errbuf, errlen, "Unknown function in eval: %s", t.text); free(stack); return 0; }
                if (fe->arity == 1) {
                    if (sz < 1) { snprintf(errbuf, errlen, "Not enough operands for %s()", t.text); free(stack); return 0; }
                    double a = POP();
                    double res;
                    fn1 f1 = (fn1)fe->func;
                    res = f1(a);
                    PUSH(res);
                } else if (fe->arity == 2) {
                    if (sz < 2) { snprintf(errbuf, errlen, "Not enough operands for %s()", t.text); free(stack); return 0; }
                    double b = POP(); double a = POP();
                    double res;
                    fn2 f2 = (fn2)fe->func;
                    res = f2(a,b);
                    PUSH(res);
                } else {
                    snprintf(errbuf, errlen, "Unsupported arity for function %s", t.text);
                    free(stack); return 0;
                }
            }
        } else {
            snprintf(errbuf, errlen, "Unexpected token in RPN");
            free(stack); return 0;
        }
    }
    if (sz != 1) { snprintf(errbuf, errlen, "Invalid expression (stack size %zu)", sz); free(stack); return 0; }
    *result = stack[0];
    free(stack);
    return 1;
    #undef PUSH
    #undef POP
}

#define HISTORY_SIZE 100
static char *history[HISTORY_SIZE];
static size_t history_count = 0;

static void add_history(const char *expr) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(expr);
    } else {
        free(history[0]);
        memmove(history, history+1, (HISTORY_SIZE-1)*sizeof(char*));
        history[HISTORY_SIZE-1] = strdup(expr);
    }
}

static void print_help(void) {
    puts("Modern C Calculator - commands:");
    puts("  help        : show this help");
    puts("  exit / quit : exit calculator");
    puts("  history     : show previous expressions");
    puts("  mem store   : store last result in memory");
    puts("  mem recall  : recall memory");
    puts("  mem clear   : clear memory");
    puts("You can use functions: sin(), cos(), tan(), asin(), acos(), atan(), sqrt(), ln(), log(), exp(), pow(x,y), abs()");
    puts("Constants: pi, e");
    puts("Use '_' (underscore) to refer to last result.");
    puts("Examples: 2 + 3*(4-1), sin(pi/2) + ln(e), pow(2,3) + sqrt(16)");
}

int main(void) {
    char *line = NULL;
    size_t len = 0;
    double memory = 0.0;
    int has_memory = 0;
    double last_result = 0.0;
    int has_last = 0;
    puts("Modern C Calculator (type 'help' for commands, 'exit' to quit)");
    while (1) {
        printf("> ");
        fflush(stdout);
        ssize_t nread = getline(&line, &len, stdin);
        if (nread <= 0) break;
        char *input = (char*)trim(line);
        if (strlen(input) == 0) continue;
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) break;
        if (strcmp(input, "help") == 0) { print_help(); continue; }
        if (strcmp(input, "history") == 0) {
            for (size_t i = 0; i < history_count; ++i) printf("%4zu: %s\n", i+1, history[i]);
            continue;
        }
        if (strncmp(input, "mem", 3) == 0) {
            char cmd[32] = {0};
            if (sscanf(input, "mem %31s", cmd) == 1) {
                if (strcmp(cmd, "store") == 0) { memory = last_result; has_memory = has_last; printf("Stored %g in memory\n", memory); }
                else if (strcmp(cmd, "recall") == 0) { if (has_memory) printf("Memory = %g\n", memory); else printf("Memory empty\n"); }
                else if (strcmp(cmd, "clear") == 0) { has_memory = 0; printf("Memory cleared\n"); }
                else printf("Unknown mem command. Use: mem store|recall|clear\n");
            } else {
                printf("mem store|recall|clear\n");
            }
            continue;
        }
        // replace underscore '_' with last result numeric literal if available
        char expanded[4096];
        expanded[0] = 0;
        if (has_last) {
            const char *p = input;
            while (*p) {
                if (*p == '_') {
                    char tmp[64];
                    snprintf(tmp, sizeof tmp, "%g", last_result);
                    strncat(expanded, tmp, sizeof(expanded)-strlen(expanded)-1);
                    ++p;
                } else {
                    size_t cur = strlen(expanded);
                    if (cur + 2 < sizeof(expanded)) {
                        expanded[cur] = *p;
                        expanded[cur+1] = 0;
                    }
                    ++p;
                }
            }
        } else {
            strncpy(expanded, input, sizeof(expanded)-1);
            expanded[sizeof(expanded)-1] = 0;
        }
        // tokenize
        TokenArray ta = tokenize(expanded);
        // put identifiers 'neg' unary support function into functions table dynamically? 'neg' handled as special-case
        // convert to RPN
        RPN rpn; rpn_init(&rpn);
        char err[256] = {0};
        if (!to_rpn(&ta, &rpn, err, sizeof(err))) {
            printf("Parse error: %s\n", err);
            ta_free(&ta); rpn_free(&rpn);
            continue;
        }
        // evaluate
        double res = 0;
        if (!evaluate_rpn(&rpn, &res, err, sizeof(err), last_result)) {
            printf("Evaluation error: %s\n", err);
            ta_free(&ta); rpn_free(&rpn);
            continue;
        }
        printf("= %.*g\n", 12, res);
        last_result = res; has_last = 1;
        add_history(input);
        // cleanup
        ta_free(&ta);
        rpn_free(&rpn);
    }
    free(line);
    for (size_t i = 0; i < history_count; ++i) free(history[i]);
    return 0;
}