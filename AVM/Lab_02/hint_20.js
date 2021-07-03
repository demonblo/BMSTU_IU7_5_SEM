"use strict";

const express = require("express");

const app = express();
const port = 5015;
app.listen(port);
console.log("My server on port " + port);

app.get("/calculate/sum", function(request, response) {
    const a = request.query.a;
    const b = request.query.b;
    const aInt = parseInt(a);
    const bInt = parseInt(b);
    const sInt = aInt + bInt;
    const answerJSON = JSON.stringify({result: sInt});
    response.end(answerJSON);
});

/*
Запускаем программу

npm start
Запускаем браузер и вбиваем в адресную строку

http://localhost:5015/calculate/sum?a=12&b=6
В браузере появится следующий ответ

{"result":18}
Таким образом, мы смогли запустить сервер на порте и написали код для приёма и обработки запроса типа GET
*/