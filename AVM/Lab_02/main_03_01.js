"use strict"

let table = [];
let fs = require("fs");
let readlineSync = require('readline-sync');
let count = readlineSync.question("Input N: ");

for (let i = 0; i < count; i++) {
    let reqString = readlineSync.question("Input string: ");
    if ((reqString.length) % 2 === 0) {
        table.push(reqString);
    } 
}

let outputString = JSON.stringify(table);
let fileName = "output_03_01.txt";
fs.writeFileSync(fileName, outputString);