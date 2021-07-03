"use strict"

let fs = require("fs");
let fileName = "input_03_02.txt";
let inputString = fs.readFileSync(fileName, "utf8");
let jsonString = JSON.parse(inputString);

function CompareToVowels(letter) {
    let vowels = ["a", "u", "e", "o", "y", "i", "A", "U", "E", "O", "Y", "I"];
    for (let key in vowels) {
        if (letter === vowels[key]) {
            return true;
        }
    }    

    return false;
}

for (let i in jsonString.mass) {
    let flag = true;
    for (let j in jsonString.mass[i]) {
        if (CompareToVowels(jsonString.mass[i].charAt(j)) === false) {
            flag = false;
        }
    }
    
    if (flag === true) {
        console.log(jsonString.mass[i]);
    }
}