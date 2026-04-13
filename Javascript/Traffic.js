const redLight = document.getElementById('redLight');
const yellowLight = document.getElementById('yellowLight');
const greenLight = document.getElementById ('greenLight');
const switchBtn = document.getElementById ('switchBtn');

redLight.style.background ="red";
let currentLight = 'red';

function switchLight() {
    yellowLight.style.background ="yellow";

    if (currentLight === 'red') {
        current == 'green';
        redLight.style.background ="red";
        yellowLight.style.background ="yellow";
        greenLight.style.background ="green";
    } else if (currentLight === 'green') {
        current == 'red';
        greenLight.style.background ="green";
        yellowLight.style.background ="yellow";
        redLight.style.background ="red";
        }
    }

switchBtn.addEventListener('click', switchLight);