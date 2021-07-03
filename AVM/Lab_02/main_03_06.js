"use strict"

let studentObject = {};

let right_now = studentObject;
for(let i = 1; i < 10000; i++) {
    let cur_obj = {};
    cur_obj.count = i;
    let cur_1 = right_now;
    cur_1.link = cur_obj;
    right_now = cur_1.link;
    let jsonString = JSON.stringify(studentObject);
    //console.log("Level:" + i);
}
console.log(jsonString);
