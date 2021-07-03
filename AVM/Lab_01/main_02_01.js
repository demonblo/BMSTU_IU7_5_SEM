"use strict"

class Dot {
    Init (x, y) {
        this.x = x;
        this.y = y;
    }

    Output () {
        console.log("[" + this.x + ", " + this.y + "]");
    }
}

class Cut {
    Init (beginDot, endDot) {
        this.begin = beginDot;
        this.end = endDot;
    }

    Output () {
        let firstMas = "Begin of the cut: [" + this.begin.x + " ," + this.begin.y + "]";
        let secondMas = "End of the cut: [" + this.end.x + " ," + this.end.y + "]";
        console.log(firstMas);
        console.log(secondMas);
    }

    FindLength () {
        let x1 = this.begin.x;
        let y1 = this.begin.y;
        let x2 = this.end.x;
        let y2 = this.end.y;

        return Math.sqrt((x2-x1)*(x2-x1) + (y2-y1) * (y2-y1));
    }
}


let fDot = new Dot();
fDot.Init(0, 0);
let sDot = new Dot();
sDot.Init(2, 2);
let cutter = new Cut();
cutter.Init(fDot, sDot);
cutter.Output();
console.log(cutter.FindLength());