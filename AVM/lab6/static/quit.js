"use strict";

window.onload = function() {
    // button
    const btn = document.getElementById("quit-btn");

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
        
        let url = `/api/delete`;
        
        ajaxGet(url, function(stringAnswer) {
            if (stringAnswer === "OK") {
                location.href = `/loginPage.html`
            }
        });
    };
};