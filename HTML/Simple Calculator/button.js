// Modern calculator logic with keyboard support and safe evaluation
(() => {
  const displayEl = document.getElementById('expression');
  const keypad = document.querySelector('.keypad');
  const themeSwitch = document.getElementById('theme-switch');

  let expr = '';

  function render() {
    displayEl.textContent = expr === '' ? '0' : expr;
  }

  function append(value) {
    // prevent leading zeros like "00"
    if (expr === '0' && value === '0') return;
    if (expr === '0' && value !== '.' && /\d/.test(value)) expr = value;
    else expr += value;
    render();
  }

  function clearAll() {
    expr = '';
    render();
  }

  function del() {
    expr = expr.slice(0, -1);
    render();
  }

  function toggleParen() {
    // simple helper: insert '(' if counts equal or last is operator, else ')'
    const opens = (expr.match(/\(/g) || []).length;
    const closes = (expr.match(/\)/g) || []).length;
    const last = expr.slice(-1);
    if (opens === closes || /[+\-*/(]$/.test(last)) {
      expr += '(';
    } else {
      expr += ')';
    }
    render();
  }

  function handlePercent() {
    // Insert % character (will be processed during evaluation)
    expr += '%';
    render();
  }

  function safeEvaluate(input) {
    if (!input || input.trim() === '') return '';
    // convert percentages like 50% to (50/100)
    const withPercents = input.replace(/(\d+(\.\d+)?)%/g, '($1/100)');
    // allow only digits, operators, parentheses, dots, spaces
    const safeRe = /^[0-9+\-*/().\s]+$/;
    if (!safeRe.test(withPercents)) throw new Error('Invalid characters');
    // Evaluate safely using Function (slightly safer than direct eval)
    // still only use after sanitization above
    // limit length to avoid DoS
    if (withPercents.length > 200) throw new Error('Expression too long');
    // eslint-disable-next-line no-new-func
    const result = Function('"use strict"; return (' + withPercents + ')')();
    if (typeof result === 'number' && !Number.isFinite(result)) throw new Error('Math error');
    return result;
  }

  function evaluate() {
    try {
      const res = safeEvaluate(expr);
      if (res === '' || res === undefined) {
        expr = '';
      } else {
        // format result to avoid long floats
        if (Number.isFinite(res)) {
          expr = Number.isInteger(res) ? String(res) : String(parseFloat(res.toPrecision(12)).toString());
        } else {
          throw new Error('Invalid result');
        }
      }
      render();
    } catch (err) {
      // show briefly an error message
      const prev = displayEl.textContent;
      displayEl.textContent = 'Error';
      setTimeout(() => { displayEl.textContent = prev; }, 900);
    }
  }

  // Button clicks
  keypad.addEventListener('click', (e) => {
    const btn = e.target.closest('button');
    if (!btn) return;
    const action = btn.dataset.action;
    const value = btn.dataset.value;

    if (action === 'clear') clearAll();
    else if (action === 'delete') del();
    else if (action === 'equals') evaluate();
    else if (action === 'paren') toggleParen();
    else if (action === 'percent') handlePercent();
    else if (value) append(value);
  });

  // Keyboard support
  window.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') { e.preventDefault(); evaluate(); return; }
    if (e.key === 'Backspace') { e.preventDefault(); del(); return; }
    if (e.key === 'Escape') { e.preventDefault(); clearAll(); return; }
    if (e.key === '%') { e.preventDefault(); handlePercent(); return; }
    if (e.key === '(' || e.key === ')') { e.preventDefault(); expr += e.key; render(); return; }
    // allow digits and operators
    if (/^[0-9+\-*/.]$/.test(e.key)) {
      e.preventDefault();
      append(e.key);
    }
  });

  // Theme toggle (light/dark)
  themeSwitch.addEventListener('change', (e) => {
    if (e.target.checked) document.documentElement.classList.add('light');
    else document.documentElement.classList.remove('light');
  });

  // Initialize
  render();
})();