"use strict"

let fs = require("fs");
let readlineSync = require('readline-sync');
let N = readlineSync.question("Input N: ");
let outp = "";
let arr = fs.readdirSync("./");

for (let i = 0; i < N; i++) {
    let fileName = readlineSync.question("Input file's name: ");
    if(!(arr.includes(fileName))) {
        console.log("There is no such file!");
        return -1;
    }
    let contentString = fs.readFileSync(fileName, "utf8");
    outp += contentString;
}

fs.writeFileSync("task_03_05_output.txt", outp);
