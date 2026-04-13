#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("=== KALKULATOR SEDERHANA ===\n");
    printf("Masukkan angka pertama: ");
    scanf("%f", &num1);
    
    printf("Masukkan operator (+, -, *, /): ");
    scanf(" %c", &operator); // Spasi sebelum %c untuk skip whitespace
    
    printf("Masukkan angka kedua: ");
    scanf("%f", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Hasil: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Hasil: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Hasil: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Hasil: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Pembagian dengan nol tidak mungkin!\n");
            }
            break;
        default:
            printf("Operator tidak valid!\n");
    }

    return 0;
}