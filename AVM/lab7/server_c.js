'use strict';

const express = require('express');
const request = require("request");
const bodyParser = require('body-parser');

const app = express();
const port = 5001;
app.listen(port);
console.log(`Server on port ${port}`);

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json())

app.set('view engine', 'hbs');

app.use(function(req, res, next) {
    res.header('Cache-Control', 'no-cache, no-store, must-revalidate');
    res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
    res.header('Access-Control-Allow-Origin', '*');
    next();
});

function sendPost(url, body, callback) {
    const headers = {};
    headers['Cache-Control'] = 'no-cache, no-store, must-revalidate';
    headers['Connection'] = 'close';
    headers['Content-type'] = 'application/json';
    request.post({
        url: url,
        body: body,
        headers: headers,
    }, function (error, response, body) {
        callback(error, response.statusCode, body);
    });
}

function sendGet(url,  callback) {
    const headers = {};
    headers['Cache-Control'] = 'no-cache, no-store, must-revalidate';
    headers['Connection'] = 'close';
    request.get({
        url: url,
        headers: headers,
    }, function (error, response, body) {
        callback(error, body);
    });
}

app.get('/vehicle', function (request, response) {
    return response.render('vehicle_get_form.hbs', {});
});

app.post('/vehicle', function (request, response) {
    const name  = encodeURIComponent(request.body.name);
    sendGet(`http://localhost:5002/select/record?name=${name}`, function(error, answerString) {
        if (error) {
            return response.render('vehicle_get_form.hbs', Object.assign({error: error}, request.body));
        }
        const answerObject = JSON.parse(answerString);
        if (answerObject.error) {
            return response.render('vehicle_get_form.hbs', Object.assign({error: answerObject.error}, request.body));
        }
        response.render('vehicle.hbs', answerObject)
    });
});

app.get('/warehouse', function (request, response) {
    return response.render('warehouse_form.hbs');
});

app.post('/warehouse', function (request, response) {
    const name  = encodeURIComponent(request.body.name);
    sendGet(`http://localhost:5003/select/record?name=${name}`, function(error, answerString) {
        if (error) {
            return response.render('warehouse_form.hbs', Object.assign({error: error}, request.body));
        }
        const answerObject = JSON.parse(answerString);
        if (answerObject.error) {
            return response.render('warehouse_form.hbs', Object.assign({error: answerObject.error}, request.body));
        }
        response.render('warehouse.hbs', answerObject)
    });
});

app.get('/add_vehicle', function (request, response) {
    return response.render('vehicle_add_form.hbs');
});


app.post('/add_vehicle', function (request, response) {
    sendPost(`http://localhost:5002/insert/record`, JSON.stringify(request.body), function(error, status, answerString) {
        if (error) {
            return response.render('vehicle_add_form.hbs', Object.assign({error: error}, request.body));
        }
        if (status === 200) {
            return response.render('vehicle.hbs', request.body);
        }
        const answerObject = JSON.parse(answerString);
        if (answerObject.error) {
            return response.render('vehicle_add_form.hbs', Object.assign({error: answerObject.error}, request.body));
        }
    });
});

app.get('/add_warehouse', function (request, response) {
    return response.render('warehouse_add_form.hbs');
});

app.post('/add_warehouse', function (request, response) {
    const name = request.body.name;
    const vehicles = [];
    for (const [key, value] of Object.entries(request.body)) {
        if (key[0] === 'v') {
            vehicles.push(value);
        }
    }
    const whObj = {name, vehicles}
    sendPost(`http://localhost:5003/insert/record`, JSON.stringify(whObj),
            function(error, status, answerString) {
        if (error) {
            return response.render('warehouse_add_form.hbs', Object.assign({error: error}, whObj));
        }
        if (status === 200) {
            return response.render('warehouse.hbs', whObj);
        }
        const answerObject = JSON.parse(answerString);
        if (answerObject.error) {
            return response.render('warehouse_add_form.hbs', Object.assign({error: answerObject.error}, whObj));
        }
    });
});

app.get('/', function(request, response) {
        return response.redirect('/index.html');
});

const way = __dirname + '/static';
app.use(express.static(way));
