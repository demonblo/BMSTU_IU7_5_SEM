"use strict"

const fs = require("fs");
const express = require("express");
const app = express();
const port = 5015;
app.listen(port);
console.log("My server on port " + port);
let inputString = fs.readFileSync("input_04_02.txt", "utf8");


app.get("/me/page", function(request, response) {
    const nameString = request.query.p;
    if (fs.existsSync(nameString)) {
        const contentString = fs.readFileSync(nameString, "utf8");
        response.end(contentString);
    } else {
        const contentString = fs.readFileSync("bad.html", "utf8");
        response.end(contentString);
    }
});

app.get("/find/byindex", function(request, response) {
    let index = request.query.index;
    let indexInt = parseInt(index);
    let jSonString = JSON.parse(inputString);
    let answ = jSonString.mass[indexInt];
    let answerJSON = JSON.stringify({result: answ});
    response.end(answerJSON);
});