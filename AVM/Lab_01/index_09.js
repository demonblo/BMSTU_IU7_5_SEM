"use strict";

class SumFinder {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    getSum() {
        return this.a + this.b;
    }
}

class MulTwoFinder {
    init(k) {
        this.k = k;
    }

    getMulTwo() {
        return 2 * this.k;
    }
}

class PerimeterFinder {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.sumFinderObj = new SumFinder(x, y);
        this.mulTwoFinderObj = new MulTwoFinder();
    }

    getPerimeter() {
        let sum = this.sumFinderObj.getSum();
        this.mulTwoFinderObj.init(sum);
        let mul = this.mulTwoFinderObj.getMulTwo();
        return mul;
    }
}

let p1 = new PerimeterFinder(7, 8);
let p2 = new PerimeterFinder(30, 70);

let valueP1 = p1.getPerimeter();
let valueP2 = p2.getPerimeter();

console.log(valueP1);
console.log(valueP2);