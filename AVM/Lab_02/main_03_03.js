"use strict"

let fs = require("fs");
let readlineSync = require('readline-sync');
let expansion = readlineSync.question("Input expansion: ");
let fullExp = "." + expansion;
let folder = readlineSync.question("Input folder adress: ");
let arr = fs.readdirSync(folder);

for (let i = 0; i < arr.length; i++) {
    if (arr[i].includes(fullExp)) {
        console.log("file name: " + arr[i]);
        let contentString = fs.readFileSync(arr[i], "utf8");
        console.log("file content: " + contentString);
    }
}
