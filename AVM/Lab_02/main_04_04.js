"use strict"

const express = require("express");
const fs = require("fs");
const app = express();
const port = 5016;
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

app.get("/find/mass", function(request, response) {
    const a = request.query.a;
    const b = request.query.b;
    const c = request.query.c;
    let mass = [];
    const aInt = parseInt(a);
    const bInt = parseInt(b);
    const cInt = parseInt(c);
    for (let i = aInt; i <= bInt; i++) {
        if (i % cInt === 0) {
            mass.push(i);
        }
    }
    const answerJSON = JSON.stringify({result: mass});
    response.end(answerJSON);
});