"use strict";

const jsonString = '{"firstname":"Maxim","lastname":"Johnson","marks":[5,5,3,2,5]}';

const manObject = JSON.parse(jsonString);

console.log("Firstname: " + manObject.firstname);
console.log("Lastname: " + manObject.lastname);

for(let i = 0; i < manObject.marks.length; i++) {
    const mark = manObject.marks[i];
    console.log("Mark: " + mark);
}