"use strict";

const fs = require("fs");

const express = require("express");

const app = express();
const port = 5015;
app.listen(port);
console.log("My server on port " + port);

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

app.get("/calculate/sum", function(request, response) {
    const a = request.query.a;
    const b = request.query.b;
    const c = request.query.c;
    const aInt = parseInt(a);
    const bInt = parseInt(b);
    const cInt = parseInt(c);
    const maxInt = Math.max(aInt, bInt, cInt);
    const answerJSON = JSON.stringify({result: maxInt});
    response.end(answerJSON);
});

app.get("/get/array/value", function(request, response) {
    const i = request.query.i;
    const iInt = parseInt(i);
    const jsonArray = fs.readFileSync("array_info.txt", "utf-8");
    const array = JSON.parse(jsonArray);
    const answerJSON = JSON.stringify({result: array[iInt]});
    response.end(answerJSON);
});

app.get("/generate/array", function(request, response) {
    const a = request.query.a;
    const b = request.query.b;
    const c = request.query.c;
    const aInt = parseInt(a);
    const bInt = parseInt(b);
    const cInt = parseInt(c);
    let array = [];
    for (let value = aInt; value <= bInt; value++) {
        if (value % cInt === 0) {
            array.push(value);
        }
    }
    const answerJSON = JSON.stringify({result: array});
    response.end(answerJSON);
});