"use strict";

window.onload = function() {

    const emailField = document.getElementById("field-email");

    const btn = document.getElementById("get-btn");

    const label = document.getElementById("result-label");

    function ajaxGet(urlString, callback) {
        let r = new XMLHttpRequest();
        r.open("GET", urlString, true);
        r.setRequestHeader("Content-Type", "application/json;charset=UTF-8"); //text/plain;charset=UTF-8");
        r.send(null);
        r.onload = function() {
            callback(r.response);
        };
    }

    // click event
    btn.onclick = function() {
        const email = emailField.value;
        const url = `/person?email=${email}`;
        ajaxGet(url, function(stringAnswer) {
            const objectAnswer = JSON.parse(stringAnswer);
            const result = objectAnswer.result;
            label.innerHTML = `Result: ${result}`;
        });
    };
};
