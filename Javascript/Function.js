function logNumberType(number) {
    if (number > 0) {
        console.log('Positive');
    } else if (number < 0) {
        console.log('Negative');
    } else {
        console.log('Netral');
    }
}

function sayHappyBirthday(name, age) {
    console.log('Selamat ulang tahun! ' + name + ' Umur kamu sekarang adalah ' + age + ' tahun ');
};

function add(x, y) {
    const z = x + y;
    console.log(x + ' Ditambah ' + y + ' hasilnya adalah: ' + z);
}


logNumberType(10);
logNumberType(-5);
logNumberType(0);

sayHappyBirthday('Andi', 25);
sayHappyBirthday('Budi', 30);
sayHappyBirthday('Citra', 22);

add(5, 10);