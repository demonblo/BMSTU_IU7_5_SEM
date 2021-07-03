"use strict";

const obj = {};
obj.x = 17;
obj.y = -45;
obj.z = 0;

const jsonString = JSON.stringify(obj);
console.log(jsonString);