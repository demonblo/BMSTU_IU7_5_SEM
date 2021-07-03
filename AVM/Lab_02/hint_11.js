"use strict";

const readlineSync = require('readline-sync');

const arr = [];

let value = true;

while(value !== "") {
    value = readlineSync.question("Input value: ");
    if(value !== "") arr.push(value);
}

for(let i = 0; i < arr.length; i++) {
    const message = i + ") " + arr[i];
    console.log(message);
}