"use strict";

const readlineSync = require('readline-sync');

const a = readlineSync.question("Input A: ");
const b = readlineSync.question("Input B: ");

const result = parseInt(a) - parseInt(b);
console.log(result);