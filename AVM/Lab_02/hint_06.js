"use strict";

const fs = require("fs");

const nameString = "a.txt";

if (fs.existsSync(nameString)) {
    console.log("File exists");
} else {
    console.log("File was not found");
}
