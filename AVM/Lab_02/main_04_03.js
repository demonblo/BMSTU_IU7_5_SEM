"use strict";

const fs = require("fs");
const express = require("express");
const app = express();
const port = 5015;
app.listen(port);
console.log("My server on port " + port);

function build_html(fields, address){
    let html_file = '<!DOCTYPE html>\n\
<html>\n\
<head>\n\
    <meta charset = "UTF-8">\n\
    <title>Результат</title>\n\
</head>\n\
<body>\n\
    <h1> Реузльтат</h1>\n\
    <form method="GET" action="/find/'+ address +'">\n'

    for (let field of fields){
        html_file += '     <p>' + field + '</p>\n';
        html_file += '     <input name = "' + field + '" spellcheck = "false" autocomplete = "off">\n'
    }

    html_file += '     <br>\n\
        <br>\n\
        <input type="submit" value="Отправить запрос">\n\
    </form>\n\
</body>\n\
</html>'

    return html_file;
}

app.get("/me/page", function(request, response) {
    const fileName = request.query.p;
    console.log(fileName);
    if (fs.existsSync(fileName)) {
        const contentString = fs.readFileSync(fileName, "utf8");
        response.end(contentString);
    } else {
        const contentString = fs.readFileSync("bad.html", "utf8");
        response.end(contentString);
    }
});

app.get("/find/by_fields", function(request, response){
    let fields = request.query.fields;
    let addresses = request.query.address;
    fields = fields.split(",");
    let result_html = build_html(fields, addresses);
    app.get("/find/" + addresses, function(request, response) {
        let arr = request.query;
        let string = JSON.stringify(arr);
        response.end(string);
    });
    response.end(result_html);
})
