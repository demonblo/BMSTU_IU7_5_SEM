"use strict";

const fs = require("fs");

const nameString = "a.txt";
const contentString = "Hello world" + "\n" + "We love JS";

fs.writeFileSync(nameString, contentString);

console.log("Create File OK");