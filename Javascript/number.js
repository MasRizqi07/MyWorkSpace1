const priceApple = 5000;
const priceBanana = 10000;
const totalApple = 3;
const totalBanana = 2;
const discount = 0.1;

const originalPrice = priceApple * totalApple + priceBanana * totalBanana;
const price = originalPrice - originalPrice * discount;
console.log('Total harga yang harus dibayar adalah Rp ' + price);