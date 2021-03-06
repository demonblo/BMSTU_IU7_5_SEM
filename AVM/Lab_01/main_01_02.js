"use strict"

class Student {
    constructor(groupName, studCard) {
        this.groupName = groupName;
        this.studCard = studCard;
        this.grades = [];
    }
}

class StudentsTable {
    constructor() {
        this.table = [];
    }

    SearchGroup (toFind) {
        for (let key in this.table) {
            if (this.table[key].groupName === toFind) {
                return key;
            }
        }
    
        return false;
    }

    SearchStud (toFind) {
        for (let key in this.table) {
            if (this.table[key].studCard === toFind) {
                return key;
            }
        }
    
        return false;
    }

    SearchAllGroup (toFind) {
        let key = this.SearchGroup(toFind);
        if (key === false) {
            console.log("There is no such group!");
            return false;
        }
        for (let key in this.table) {
            if (this.table[key].groupName === toFind) {
                console.log("Group: " + this.table[key].groupName + ", Student's card: " + this.table[key].studCard);
                console.log("Grades: " + this.table[key].grades);
            }
        }
    
        return true;
    }
    
    CreateStud (toCreateGroupName, toCreateStudCard) {
        let key = this.SearchStud(toCreateStudCard);
        if (key !== false) {
            console.log("Such student's card is already exist!");
            return false;
        }
        this.table.push(new Student(toCreateGroupName, toCreateStudCard))
    
        return true;
    }

    UpdateGroup (groupNameToUp, studCard) {
        let key = this.SearchStud(studCard);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        this.table[key].groupName = groupNameToUp;

        return true;
    }

    UpdateStudCard (studCardToUp, studCard) {
        let key = this.SearchStud(studCard);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        let notkey = this.SearchStud(studCardToUp);
        if (notkey !== false) {
            console.log("Such student's card is already exist!");
            return false;
        }
        this.table[key].studCard = studCardToUp;

        return true;
    }

    AddGrade (studCard, grade) {
        let key = this.SearchStud(studCard);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        this.table[key].grades.push(grade);

        return true;
    }

    DeleteThisGrade (studCard, numb) {
        let key = this.SearchStud(studCard);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        
        return this.table[key].grades.splice(numb, 1);
    }

    ReadByStudCard (studCard) {
        let key = this.SearchStud(studCard);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        console.log("Group: " + this.table[key].groupName + ", Student's card: " + this.table[key].studCard);
        console.log("Grades: " + this.table[key].grades);

        return true;
    }

    Delete (toDelete) {
        let key = this.SearchStud(toDelete);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        this.table.splice(key, 1); 
        
        return true;
    }

    StudentAverageGrade (studCard) {
        let key = this.SearchStud(studCard);
        if (key === false) {
            console.log("There is no such student!");
            return false;
        }
        let answ = 0;
        let count = 0;
        for (let i in this.table[key].grades) {
            answ += this.table[key].grades[i];
            ++count;
        }

        return answ/count;
    }

    FindMostGrades (groupName) {
        let key = this.SearchGroup(groupName);
        if (key === false) {
            console.log("There is no such group!");
            return false;
        }
        let most = 0;
        let answ = 0;
        for (let i in this.table) {
            if (this.table[i].groupName === groupName) {
                if (this.table[i].grades.length > most) {
                    answ = i;
                    most = this.table[i].grades.length;
                }
            }
        }

        if (most > 0) {
            console.log("Group: " + this.table[answ].groupName + ", Student's card: " + this.table[answ].studCard);
            console.log("Grades: " + this.table[answ].grades);
            return true;
        }
        
        console.log("There are no grades in the group!");
        return false;
    }
    
    FindNoGrades (groupName) {
        let key = this.SearchGroup(groupName);
        if (key === false) {
            console.log("There is no such group!");
            return false;
        }
        for (let i in this.table) {
            if (this.table[i].groupName === groupName) {
                if (this.table[i].grades.length === 0) {
                    console.log("Group: " + this.table[i].groupName + ", Student's card: " + this.table[i].studCard);
                    console.log("Grades: " + this.table[i].grades);
                    return true;
                }
            }
        }

        console.log("There is no student without ane grades!");
        return false;
    }
}

let table = new StudentsTable();
table.CreateStud("????-52??", "18??148");
table.CreateStud("????-53??", "18??158");
table.CreateStud("????-52??", "18??147");
table.CreateStud("????-52??", "18??169");
table.CreateStud("????-53??", "18??132");
table.AddGrade("18??148", 4);
table.AddGrade("18??148", 5);
table.AddGrade("18??148", 4);
table.AddGrade("18??147", 4);
table.AddGrade("18??147", 4);
table.AddGrade("18??147", 4);
table.AddGrade("18??147", 4);
console.log(table);

console.log("Average grades of the 18??148:");
console.log(table.StudentAverageGrade("18??148"));
console.log("Info about ????-52?? group:");
table.SearchAllGroup("????-52??");
console.log("Info about student with no grades in ????-52?? group:");
table.FindNoGrades("????-52??");
console.log("Info about student with the most grades in ????-52?? group:");
table.FindMostGrades("????-52??");
table.DeleteThisGrade("18??147", 0);
table.DeleteThisGrade("18??147", 2);
console.log("Info about student with the most grades in ????-52?? group AFTER REMOVING:");
table.FindMostGrades("????-52??");
