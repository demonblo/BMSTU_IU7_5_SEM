"use strict"

const express = require("express");
const fs = require("fs");
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

app.get("/find/max", function(request, response) {
    const a = request.query.a;
    const b = request.query.b;
    const c = request.query.c;
    let max = 0;
    const aInt = parseInt(a);
    const bInt = parseInt(b);
    const cInt = parseInt(c);
    if (aInt >= bInt && aInt >= cInt) {
        max = aInt;
    }
    else if (bInt >= aInt && bInt >= cInt) {
        max = bInt;
    }
    else if (cInt >= aInt && cInt >= bInt) {
        max = cInt;
    }
    const answerJSON = JSON.stringify({result: max});
    response.end(answerJSON);
});