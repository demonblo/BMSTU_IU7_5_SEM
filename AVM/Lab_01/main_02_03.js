"use strict";
 
const first_interv = 2000;
const second_interv = 1000;

let seconds;

function first () {
    seconds = 0;
    let interval_1 = setInterval(() => {
        seconds++;
        console.log("Seconds: " + seconds);
        if (seconds === 10) {
            clearInterval(interval_1);
            second();
        }
    }, first_interv);
}

function second () {
    seconds = 10;
    let interval_2 = setInterval(() => {
        seconds++;
        console.log("Seconds: " + seconds);
        if (seconds === 20) {
            clearInterval(interval_2);
            first();
        }
    }, second_interv);
}

first();
