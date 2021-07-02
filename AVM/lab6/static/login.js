"use strict";

window.onload = function() {
    // input fields
    const loginField = document.getElementById("field-login");
    const passwordFiled = document.getElementById("field-password");

    // button
    const btn = document.getElementById("auth-btn");

    // label
    const label = document.getElementById("error-label");

    // ajax get
    function ajaxGet(urlString, callback) {
        let r = new XMLHttpRequest();
        r.open("GET", urlString, true);
        r.setRequestHeader("Content-Type", "text/plain;charset=UTF-8");
        r.send(null);
        r.onload = function() {
            callback(r.response);
        };
    };

    // click event
    btn.onclick = function() {
        
        const login = loginField.value;
        const password = passwordFiled.value;
        
        let url = `/api/save?login=${login}&password=${password}`;
        
        ajaxGet(url, function(stringAnswer) {
            let objectAnswer = JSON.parse(stringAnswer);
            let result = objectAnswer.result;
            label.innerHTML = `${result}`;
            if (result === "Success") {
                url = `/api/get`;
                ajaxGet(url, function(stringAnswer) {
                    label.innerHTML = stringAnswer
                    if (stringAnswer) {
                        objectAnswer = JSON.parse(stringAnswer);
                        result = objectAnswer.result;
                        label.innerHTML = `${result}`;
                    }
                    else {
                        location.href = `/profile`
                    }
                });
            }
        });
    };
};