"use strict";

let obj = {};

obj["a"] = "hello";
obj["b"] = false;
obj["x"] = 218;
obj["y"] = 3.14;
obj["z"] = "gorgeous";

for(let key in obj) {
    let value = obj[key];
    let message = key + " : " + value;
    console.log(message);
}

let myX = obj["x"];
console.log(myX);

obj["x"] = 1234;
obj["z"] = 6789;
console.log(obj["x"]);
console.log(obj["z"]);