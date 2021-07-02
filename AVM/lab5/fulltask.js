"use strict";

const { RSA_NO_PADDING } = require("constants");
const e = require("express");
const express = require("express");

const fs = require("fs");

const app = express();
const port = 5000;
app.listen(port);
console.log(`Server on port ${port}`);

const way = __dirname + "/static";
app.use(express.static(way));

app.use(function(req, res, next) {
    res.header("Cache-Control", "no-cache, no-store, must-revalidate");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    res.header("Access-Control-Allow-Origin", "*");
    next();
});

app.get("/sum", function(request, response) {
    const a = request.query.a;
    const b = request.query.b;
    const s = parseInt(a) + parseInt(b);
    response.end(JSON.stringify({
        result: s
    }));
});

function getPersonByEmail(email, arr) {
    let reqIndex = -1;
    for (let i = 0; i < arr.length && reqIndex === -1; i++) {
        if (arr[i]["email"] === email) {
            reqIndex = i;
        }
    }
    if (reqIndex === -1) {
        return null
    }
    return arr[reqIndex];
}

app.get("/person", function(request, response) {
    const email = request.query.email;

    let res = "";

    const fileName = "task1.txt";
    if (!fs.existsSync(fileName)) {
        res = "There is no such email.";
    }
    else {
        const contentString = fs.readFileSync(fileName, "utf-8");
        const arr = JSON.parse(contentString);
        const reqObj = getPersonByEmail(email, arr);

        if (!reqObj) {
            res = "There is no such email.";
        }
        else {
            res = JSON.stringify(reqObj);
        }
    }
    response.end(JSON.stringify({
        result: res
    }));
})

function loadBody(request, callback) {
    let body = [];
    request.on('data', (chunk) => {
        body.push(chunk);
    }).on('end', () => {
        body = Buffer.concat(body).toString();
        callback(body);
    });
}

function isUniqueNumberAndEmail(obj, arr) {
    let res = true;
    for (let i = 0; i < arr.length && res; i++) {
        if (obj["email"] === arr[i]["email"] ||
            obj["phoneNumber"] === arr[i]["phoneNumber"]) {
            res = false;
        }
    }
    return res
}

app.post("/save/info", function(request, response) {
    loadBody(request, function(body) {
        const fileName = "task1.txt";
        if (!fs.existsSync(fileName)) {
            fs.writeFileSync(fileName, "[]");
        }
        const obj = JSON.parse(body);
        const prevContentString = fs.readFileSync(fileName, "utf-8");
        const arr = JSON.parse(prevContentString);
        let resultMessage = "Success";
        if (isUniqueNumberAndEmail(obj, arr)) {
            arr.push(obj);
            const contentString = JSON.stringify(arr, null, 2);
            fs.writeFileSync("task1.txt", contentString);
        }
        else {
            resultMessage = "Not Unique";
        }
        response.end(JSON.stringify({
            result: resultMessage
        }));
    });
});