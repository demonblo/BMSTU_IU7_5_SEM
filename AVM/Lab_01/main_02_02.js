"use strict"

class Triangle {
    Init (first, second, third) {
        this.firstSide = first;
        this.secondSide = second;
        this.thirdSide = third;
    }

    CheckForExist () {
        if (this.firstSide > this.secondSide + this.thirdSide) {
            console.log("This triangle can't exist!");
            return false;
        }
        if (this.secondtSide > this.firstSide + this.thirdSide) {
            console.log("This triangle can't exist!");
            return false;
        }
        if (this.thirdSide > this.firstSide + this.secondSide) {
            console.log("This triangle can't exist!");
            return false;
        }

        console.log("This triangle can exist!");
        return true;
    }

    FindPerimetr () {
        return this.firstSide + this.secondSide + this.thirdSide;
    }

    FindSquare () {
        let p = this.FindPerimetr()/2;
        let a = (p - this.firstSide);
        let b = (p - this.secondSide);
        let c = (p - this.thirdSide);

        return Math.sqrt(p * a * b * c);
    }

    CheckIfRect () {
        if (this.firstSide * this.firstSide === this.secondSide * this.secondSide + this.thirdSide * this.thirdSide) {
            console.log("This triangle is rectangular!");
            return true;
        }
        if (this.secondSide * this.secondSide === this.firstSide * this.firstSide + this.thirdSide * this.thirdSide) {
            console.log("This triangle is rectangular!");
            return true;
        }
        if (this.thirdSide * this.thirdSide === this.firstSide * this.firstSide + this.secondSide * this.secondSide) {
            console.log("This triangle is rectangular!");
            return true;
        }

        console.log("This triangle isn't rectangular!");
        return false;
    }
}

let trian = new Triangle();
trian.Init(3, 4, 6);
trian.CheckForExist();
console.log("Perimetr of current triangle: " + trian.FindPerimetr());
console.log("Square of current triangle: " + trian.FindSquare());
trian.CheckIfRect();
let trian_01 = new Triangle();
trian_01.Init(0, 1, 2);
trian_01.CheckForExist();
console.log("Perimetr of current triangle: " + trian_01.FindPerimetr());
console.log("Square of current triangle: " + trian_01.FindSquare());
trian_01.CheckIfRect();
let trian_02 = new Triangle();
trian_02.Init(2, 2, 2);
trian_02.CheckForExist();
console.log("Perimetr of current triangle: " + trian_02.FindPerimetr());
console.log("Square of current triangle: " + trian_02.FindSquare());
trian_02.CheckIfRect();
