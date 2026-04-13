const userNames = [
    'Achmad',
    'Rizqi',
    'Mubarok',
    'Pacol'
];
const isAvengers = [
    'Thor',
    'Ironman',
    'Hulk',
    'Captain America'
];

const favoriteFoods = [
    'nasi Goreng',
    'sate',
    'bakso'
]

const newUsernames = 'Cokk';
const isTaken = userNames.includes(newUsernames);

if (isTaken) {
    console.log('Username sudah digunakan, silakan pilih username Lain');
} else {
    console.log('Username tersedia');
}

console.log(isAvengers[2]);

const text = 'Makanan Favoriteku yang kedua adalah ' + favoriteFoods[1] + '.';
console.log(text);