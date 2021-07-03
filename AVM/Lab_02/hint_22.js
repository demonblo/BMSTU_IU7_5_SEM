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
    const aInt = parseInt(a);
    const bInt = parseInt(b);
    const sInt = aInt + bInt;
    const answerJSON = JSON.stringify({result: sInt});
    response.end(answerJSON);
});