"use strict";

const fs = require("fs");
const readlineSync = require('readline-sync');

function evenLenghtStr(fileName) {  // Task 1
    let stringArray = [];
    let n = readlineSync.question("Input number of rows: ");

    for (let i = 0; i < n; i++) {
        let s = readlineSync.question("Input string: ");
        if (s.length % 2 === 0) {
            stringArray.push(s);
        }
    }

    const jsonStringArray = JSON.stringify(stringArray, null, 4);
    fs.writeFileSync(fileName, jsonStringArray);
}

function onlyVowels(fileName) {  // Task 2
    let stringArray = [];
    let vowels = "aeiou";
    console.log("Hewwo");
        const contentString = fs.readFileSync(fileName, "utf8");
        stringArray = JSON.parse(contentString);

        stringArray.forEach(string => {
            for (let i = 0; i <= string.length - 1; i++) {
                if (vowels.indexOf(string.toLowerCase().charAt(i)) < 0) {
                    stringArray.splice(stringArray.indexOf(string), 1);
                }
            }
        });

        console.log("Array of strings consist of only vowels: ", stringArray);
}

function fileContentWithRigthExtension() {  // Task 3
    const folderName = readlineSync.question("Input folder name: ");
    const extensionName = readlineSync.question("Input extension name: ");

    const filesArray = fs.readdirSync(folderName);

    filesArray.forEach(fileName => {
        if (fileName.split('.')[1] === extensionName) {
            console.log(fileName + ': ');
            console.log(fs.readFileSync(fileName, "utf8"));
        }
    });
}

function filePathShorten(filePath) {  // Task 4
    let filePathArray = filePath.split('/');
    filePath = filePath.slice(0, filePath.length - filePathArray[filePathArray.length - 1].length - 1);
    return filePath;
}

function filesOutputByPath(filePath) {  // Task 4

    while (filePath !== '') {
        console.log('\n');
        console.log(filePath);
        const filesArray = fs.readdirSync(filePath);
        console.log(filesArray);
        filesArray.forEach(fileName => {
            if (fileName.split('.')[1] === "txt") {
                let fileContent = fs.readFileSync(fileName, "utf8");
                if (fileContent.length <= 1000) {
                    console.log(fileName);
                    console.log(fileContent);
                }
            }
        });

        filePath = filePathShorten(filePath);
    }
}

function combineFiles() {  // Task 5
    let filesContentArray = [];
    let filesContentCombined = "";

    let n = readlineSync.question("Input N: ");
    for (let i = 0; i < n; i++) {
        let fileName = readlineSync.question("Input file name: ");
        if (fs.existsSync(fileName)) {
            filesContentArray.push(fs.readFileSync(fileName, "utf8"));
        }
    }

    filesContentArray.forEach(fileContent => {
        filesContentCombined += fileContent;
    });

    fs.writeFileSync("combine.txt", filesContentCombined);
}

function findMaxNestingLevel() {  // Task 6
    let objString = '{"a":""}';
    let flag = true;
    let level = 0;

    while (flag !== false) {
        objString = objString.replace('""', '{"a":""}');
        level++;

        const obj = JSON.parse(objString);

        try {
            let jsonString = JSON.stringify(obj);
        }
        catch (err) {
            console.error(err.message);
            console.log("Result:  ", level);
            flag = false;
        }
    }
}

function getNestingLevel(object, nestingLevelsNumber) { //Task 7
    console.log('Object: ', object);
    nestingLevelsNumber.levelNumber++;
    console.log('Nesting level: ', nestingLevelsNumber.levelNumber);

    for (let p in object) {
        if (typeof(object[p]) === 'object') {
            getNestingLevel(object[p], nestingLevelsNumber);
        } else {
            console.log('Value: ' + object[p]);
        }
    }
    return nestingLevelsNumber;
}

function getMaxNestingLevel(fileName) { //Task 7

    let objectExample = {
        aa: {
            ba: {
                c: 1
            },
            bb: {
                c: 12
            },
            bc: {
                c: {
                    d: [1,2],
                    e: 1234,
                    f: {
                        h: {
                            i: {
                                j: '1',
                                k: 1,
                                l: 1,
                            }
                        }
                    }
                }
            }
        }
    }

    const objString = JSON.stringify(objectExample);
    const obj = JSON.parse(objString);

    let nestingLevelsNumber = {levelNumber: -1};
    getNestingLevel(obj, nestingLevelsNumber);
    return nestingLevelsNumber.levelNumber;
}

const fileName = "data.txt";
const filePath = "/Users/teona/WebstormProjects/evm/lab3/data.txt";

//evenLenghtStr(fileName);
//onlyVowels(fileName);
//fileContentWithRigthExtension();
//filesOutputByPath(filePath);
//combineFiles();
//findMaxNestingLevel();
console.log(getMaxNestingLevel(fileName));