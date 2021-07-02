'use strict';

const num = parseInt(process.argv[2]);

let res = 1;
for (let i = 2; i <= num; i++) {
    res *= i;
}

console.log('' + res);


