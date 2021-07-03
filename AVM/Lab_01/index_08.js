"use strict";

class SumFinder {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    renderFields() {
        let messageA = "A: " + this.a;
        let messageB = "B: " + this.b;
        let fullMessage = messageA + " " + messageB;
        console.log(fullMessage);
    }

    getSum() {
        let s = this.a + this.b;
        return s;
    }
}

let first = new SumFinder(2, 7);
let second = new SumFinder(100, 45);

first.renderFields();
second.renderFields();

let firstSumValue = first.getSum();
let secondSumValue = second.getSum();

console.log(firstSumValue);
console.log(secondSumValue);