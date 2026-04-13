function sayBye(name) {
    console.log('Goodbye, ' + name + '!');
};

function add(x, y) {
    return x + y;
};

const sayBye2 = (name) => {
    console.log('Goodbye, ' + name + '!');
};

const formatAge = (name, age) => name + ' Umur saya adalah ' + age + ' tahun ';

const add2 = (x, y) => x + y;
console.log(add(2, 3));
console.log(add2(5, 7));

sayBye('Pacoel ');
sayBye2('Anjing ');

console.log(formatAge('Pacoel', 25));