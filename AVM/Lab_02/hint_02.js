"use strict";

const studentObject = {};
studentObject.firstname = "Maxim";
studentObject.lastname = "Johnson";
studentObject.marks = [5, 5, 3, 2, 5];

const jsonString = JSON.stringify(studentObject);
console.log(jsonString);