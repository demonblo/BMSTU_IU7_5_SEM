"use strict";

let firstObj = null;
let secondObj = null;

firstObj = {login: "Maxim", age: 35};

console.log(firstObj.login);
console.log(firstObj.age);

secondObj = firstObj;
secondObj["login"] = "George";
secondObj["age"] = 18;

console.log(firstObj.login);
console.log(firstObj.age);
console.log(secondObj.login);
console.log(secondObj.age);