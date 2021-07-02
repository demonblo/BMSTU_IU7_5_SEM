'use strict';

const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');

const app = express();
const port = 5003;
app.listen(port);
console.log(`Server B on port ${port}`);

app.use(function(req, res, next) {
    res.header('Cache-Control', 'no-cache, no-store, must-revalidate');
    res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
    res.header('Access-Control-Allow-Origin', '*');
    next();
});

app.use(bodyParser.json())

const storageFile = __dirname + '/warehouse.json'
if (!fs.existsSync(storageFile)) {
    fs.writeFileSync(storageFile, JSON.stringify([]))
}

app.post('/insert/record', function(request, response) {
    const newObj = request.body;
    if (newObj === undefined || newObj.name === undefined) {
        response.status(400);
        response.end(JSON.stringify({error: 'Invalid request body'}));
    }
    const data = JSON.parse(fs.readFileSync(storageFile));
    for (const el of data) {
        if (el.name === newObj.name) {
            response.status(409);
            response.end(JSON.stringify({error: 'Warehouse already exists'}));
            return;
        }
    }
    data.push(newObj);
    fs.writeFileSync(storageFile, JSON.stringify(data));
    response.sendStatus(200);
});

app.get('/select/record', function(request, response) {
    const name = request.query.name
    const data = JSON.parse(fs.readFileSync(storageFile));
    for (const el of data) {
        if (el.name === name) {
            return response.end(JSON.stringify(el));
        }
    }
    response.status(404);
    response.end(JSON.stringify({error: 'Warehouse not found'}));
});
