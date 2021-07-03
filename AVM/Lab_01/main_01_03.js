"use strict"

class Dot {
    constructor(name, x, y) {
        this.name = name;
        this.x = x;
        this.y = y;
    }
}

class DotsTable {
    constructor() {
        this.table = [];
    }

    Search (toFind) {
        for (let key in this.table) {
            if (this.table[key].name === toFind) {
                return key;
            }
        }

        return false;
    }

    Create (name, x, y) {
        let key = this.Search(name);
        if (key !== false) {
            console.log("There is already such dot!");
            return false;
        }
        this.table.push(new Dot(name, x, y));

        return true;
    }

    Read (toRead) {
        let key = this.Search(toRead);
        if (key === false) {
            console.log("There is no such dot!");
            return false;
        }
        console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");

        return true;
    }

    UpdateName (name, nameToUpdate) {
        let key = this.Search(name);
        if (key === false) {
            console.log("There is no such dot!");
            return false;
        }
        let notkey = this.Search(nameToUpdate);
        if (notkey !== false) {
            console.log("There is already such dot!");
            return false;
        }

        this.table[key].name = nameToUpdate;

        return true;
    }

    UpdateX (nameToUpdate, x) {
        let key = this.Search(nameToUpdate);
        if (key === false) {
            console.log("There is no such dot!");
            return false;
        }
        this.table[key].x = x;

        return true;
    }

    UpdateY (nameToUpdate, y) {
        let key = this.Search(nameToUpdate);
        if (key === false) {
            console.log("There is no such dot!");
            return false;
        }
        this.table[key].y = y;

        return true;
    }

    Delete (toDelete) {
        let key = this.Search(toDelete);
        if (key === false) {
            console.log("There is no such dot!");
            return false;
        }
        this.table.splice(key, 1);

        return true;
    }

    FindDistance (first, second) {
        let x1 = first.x;
        let y1 = first.y;
        let x2 = second.x;
        let y2 = second.y;

        return Math.sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    }

    FindMaxDistance () {
        let curDist = 0;
        let maxDist = 0;
        let maxFirst = 0;
        let maxSecond = 1;
        let i = 0;
        let j;
        while (i < this.table.length - 1) {
            j = i + 1;
            while (j < this.table.length) {
                curDist = this.FindDistance(this.table[i], this.table[j]);
                if (curDist > maxDist) {
                    maxFirst = i;
                    maxSecond = j;
                    maxDist = curDist;
                }
                j++;
            }

            i++;
        }

        console.log("First dot name: " + this.table[maxFirst].name + ", [" + this.table[maxFirst].x + ", " + this.table[maxFirst].y + "]");
        console.log("First dot name: " + this.table[maxSecond].name + ", [" + this.table[maxSecond].x + ", " + this.table[maxSecond].y + "]");
        console.log("Max Distance: " + maxDist);

        return true;
    }

    FindDistLowerConst (xc, yc, curConst) {
        let curDot = new Dot("cur", xc, yc);
        let curDist;
        for (let key in this.table) {
            curDist = this.FindDistance(curDot, this.table[key]);
            if (curDist <= curConst) {
                console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                console.log("Distance: " + curDist);
            }
        }

        return true;
    }

    FindDotSit (os) {
        for (let key in this.table) {
            let y = this.table[key].y;
            let x = this.table[key].x;
            if (os === "OX" || os === "Ox") {
                if (y > 0) {
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                    console.log("This dot is upper than OX");
                }
                /*if (y === 0) {
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                    console.log("This dot is on the OX");
                }*/
                if (y < 0) {
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                    console.log("This dot is lower than OX");
                }
            }
            if (os === "OY" || os === "Oy") {
                if (x > 0) {
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                    console.log("This dot is on the right side of OY");
                }
                /*if (x === 0) {
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                    console.log("This dot is on the OY");
                }*/
                if (x < 0) {
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                    console.log("This dot is on the left side of OY");
                }
            }
        }

        return true;
    }

    FindInsideZone (leftDownX, leftDownY, rightUpX, rightUpY) {
        for (let key in this.table) {
            if (this.table[key].x >= leftDownX && this.table[key].x <= rightUpX) {
                if (this.table[key].y >= leftDownY && this.table[key].y <= rightUpY){
                    console.log("Name: " + this.table[key].name + ", [" + this.table[key].x + ", " + this.table[key].y + "]");
                }
            }
        }

        return true;
    }
}

let table = new DotsTable();
table.Create("A", 2, 2);
table.Create("B", -1, 1);
table.Create("C", 1, 10);
console.log(table);
console.log("Info about dots with the most distance:");
table.FindMaxDistance();
console.log("Info about dots relatively Oy:");
table.FindDotSit("Oy");
console.log("Info about dots, which distance from the dot 0, 0 lower than 3:");
table.FindDistLowerConst(0, 0, 3);
console.log("Info about dots inside Zone where 0, 0 is left and down angle and 3, 3 is right and up angle:");
table.FindInsideZone(0, 0, 3, 3);

