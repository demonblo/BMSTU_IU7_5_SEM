"use strict";

const fs = require("fs");

const nameString = "a.txt";

const contentString = fs.readFileSync(nameString, "utf8");

console.log(contentString);