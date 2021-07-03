"use strict";

const fs = require("fs");

const nameString = "a.txt";

if (fs.existsSync(nameString)) {
    fs.unlinkSync(nameString);
    console.log("Delete complete")
} else {
    console.log("File not found");
} 