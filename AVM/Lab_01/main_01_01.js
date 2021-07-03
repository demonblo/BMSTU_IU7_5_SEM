"use strict"

class Child {
    constructor(surname, age) {
        this.surname = surname;
        this.age = age;
    }
}

class ChildsTable {
    constructor() {
        this.table = [];
    }

    Search (toFind) {
        for (let key in this.table) {
            if (this.table[key].surname === toFind) {
                return key;
            }
        }
    
        return false;
    }
    
    Create (toCreateSurname, toCreateAge) {
        let key = this.Search(toCreateSurname);
        if (key !== false) {
            console.log("Such child is already in the table!");
            return false;
        }
        this.table.push(new Child(toCreateSurname, toCreateAge))
    
        return true;
    }
    
    ReadBySurname (toRead) {
        let key = this.Search(toRead);
        if (key === false) {
            console.log("There is no such child!");
            return false;
        }
        for (let notkey in this.table) {
            if (notkey === key) {
                console.log("Surname:" + this.table[key].surname + ", age:" + this.table[key].age);
            }
        }
    
        return true;
    }
    
    UpdateSurname (toUpdate, SurnameToUp) {
        let key = this.Search(toUpdate);
        if (key === false) {
            console.log("There is no such child!");
            return false;
        }
        this.table[key].surname = SurnameToUp;
    
        return true;
    }

    UpdateAge (toUpdate, AgeToUp) {
        let key = this.Search(toUpdate);
        if (key === false) {
            console.log("There is no such child!");
            return false;
        }
        this.table[key].age = AgeToUp;
    
        return true;
    }
    
    Delete (toDelete) {
        let key = this.Search(toDelete);
        if (key === false) {
            console.log("There is no such child!");
            return false;
        }
        this.table.splice(key, 1); 
        
        return true;
    }
    
    FindAverage () {
        let average = 0;
        let count = 0;
        for (let key in this.table) {
            average += this.table[key].age;
            ++count;
        }
    
        return average/count;
    }
    
    InfoAboutTheOldest () {
        let answKey = 0;
        let answ = 0;
        for (let key in this.table) {
            if (answ < this.table[key].age) {
                answKey = key;
                answ = this.table[key].age;
            }
        }
    
        console.log("Surname:" + this.table[answKey].surname + ", age:" + answ);
        return true;
    }
    
    InfoAboutChildrenSection (low, high) {
        for (let key in this.table) {
            if (this.table[key].age >= low && this.table[key].age <= high) {
                console.log("Surname:" + this.table[key].surname + ", age:" + this.table[key].age);
            }
        }
    
        return true;
    }
    
    InfoAboutChildrenLetter (toCompare) {
        for (let key in this.table) {
            if (this.table[key].surname.charAt(0) === toCompare) {
                console.log("Surname:" + this.table[key].surname + ", age:" + this.table[key].age);
            }
        }
    
        return true;
    }
    
    InfoAboutChildrenLength (toCompare) {
        for (let key in this.table) {
            if (this.table[key].surname.length > toCompare) {
                console.log("Surname:" + this.table[key].surname + ", age:" + this.table[key].age);
            }
        }
    
        return true;
    }
    
    CompareToVowels(letter) {
        let vowels = ["a", "u", "e", "o", "y", "i", "A", "U", "E", "O", "Y", "I"];
        for (let key in vowels) {
            if (letter === vowels[key]) {
                return true;
            }
        }    
    
        return false;
    }
    
    InfoAboutChildrenVowels () {   
        for (let key in this.table) {
            if (this.CompareToVowels(this.table[key].surname.charAt(0))) {
                console.log("Surname:" + this.table[key].surname + ", age:" + this.table[key].age);
            }
        }
    
        return true;
    }
}


let table = new ChildsTable();
table.Create("Blokhin", 20);
table.Create("lFilippov", 14);
table.Create("Inshualla", 16);
table.Create("Aksenov", 18);
table.Create("Andreev", 15);
console.log(table);
console.log("Average age of cur table:" + table.FindAverage());
console.log("The oldest kid:");
table.InfoAboutTheOldest();
console.log("Info about the children between 14 and 17 ages:");
table.InfoAboutChildrenSection(14, 17);
console.log("Info abouth the children, which surnames starts with 'A':");
table.InfoAboutChildrenLetter("A");
console.log("Info abouth the children, which surnames length more than 7:");
table.InfoAboutChildrenLength(7);
console.log("Info abouth the children, which surnames starts with vowels:");
table.InfoAboutChildrenVowels();
table.UpdateSurname("aueshovich", "Blokhin");
table.Delete("lololo");
