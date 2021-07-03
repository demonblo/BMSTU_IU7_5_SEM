"use strict"

let readlineSync = require('readline-sync');
const { performance } = require('perf_hooks');

function findLevDist () {
    let matrLev = [];
    let firstWord = readlineSync.question("Input first word:");
    let secondWord = readlineSync.question("Input second word:");
    let firstLen = firstWord.length;
    let secondLen = secondWord.length;
    let time = performance.now();
    for (let i = 0; i <= secondLen; i++) {
        matrLev.push([]);
        for (let j = 0; j <= firstLen; j++) {
            if (i === 0) {
                matrLev[i].push(j);
            }
            if (i !== 0 && j === 0) {
                matrLev[i].push(i);
            }
            if (i !== 0 && j !== 0) {
                let fElem = matrLev[i][j - 1] + 1;
                let sElem = matrLev[i - 1][j] + 1;
                let tElem = matrLev[i - 1][j - 1];
                if (firstWord[j - 1] !== secondWord[i - 1]) {
                    tElem += 1;
                }
                if (fElem <= sElem && fElem <= tElem) {
                    matrLev[i].push(fElem);
                }
                else if (sElem <= fElem && sElem <= tElem) {
                    matrLev[i].push(sElem);
                }
                else if (tElem <= fElem && tElem <= sElem) {
                    matrLev[i].push(tElem);
                }
            }
        }
    }
    time = performance.now() - time;
    console.log(time/1000);
    console.log(matrLev);
    console.log("Distance of Levenstein by matrix: " + matrLev[secondLen][firstLen]);
}

function levDistRec (s1, s2, s1_len, s2_len) {
    let temp;
    let cost;
    if (s1_len === 0 || s2_len === 0) {
        temp = Math.abs(s1_len - s2_len);
    }
    else {
        if (s1[s1_len - 1] === s2[s2_len - 1]) {
            cost = 0;
        }
        else {
            cost = 1;
        }
        let firstTemp = (levDistRec(s1, s2, s1_len - 1, s2_len) + 1);
        let secondTemp = (levDistRec(s1, s2, s1_len, s2_len - 1) + 1);
        let thirdTemp = (levDistRec(s1, s2, s1_len - 1, s2_len - 1) + cost);
        if (firstTemp <= secondTemp && firstTemp <= thirdTemp) {
            temp = firstTemp;
        }
        else if (secondTemp <= firstTemp && secondTemp <= thirdTemp) {
            temp = secondTemp;
        }
        else if (thirdTemp <= firstTemp && thirdTemp <= secondTemp) {
            temp = thirdTemp;
        }
    }

    return temp;
}

function findLevDistRec () {
    let firstWord = readlineSync.question("Input first word:");
    let secondWord = readlineSync.question("Input second word:");
    let firstLen = firstWord.length;
    let secondLen = secondWord.length;
    let time = performance.now();
    let ans = levDistRec(firstWord, secondWord, firstLen, secondLen);
    time = performance.now() - time;
    console.log(time/1000);
    console.log("Distance of Levenstein by recursion: " + ans);
}

function calculate_Value(matr, i, j, s1, s2) {
    let cost;
    if (matr[i][j] != -1) {
        return matr[i][j];
    }
    else {
        if (s1[i - 1] == s2[j - 1]) {
            cost = 0;
        }
        else {
            cost = 1;
        }
        let f_temp = calculate_Value(matr, i - 1, j, s1, s2) + 1;
        let s_temp = calculate_Value(matr, i, j - 1, s1, s2) + 1;
        let t_temp = calculate_Value(matr, i - 1, j - 1, s1, s2) + cost;
        if (f_temp <= s_temp && f_temp <= t_temp) {
            matr[i][j] = f_temp;
        }
        else if (s_temp <= f_temp && s_temp <= t_temp) {
            matr[i][j] = s_temp;
        }
        else if (t_temp <= f_temp && t_temp <= s_temp) {
            matr[i][j] = t_temp;
        }

        return matr[i][j];
    }
}

function findLevDistRecMatr () {
    let matrLev = [];
    let firstWord = readlineSync.question("Input first word:");
    let secondWord = readlineSync.question("Input second word:");
    let firstLen = firstWord.length;
    let secondLen = secondWord.length;
    let time = performance.now();
    for (let i = 0; i <= secondLen; i++) {
        matrLev.push([]);
        for (let j = 0; j <= firstLen; j++) {
            if (i === 0) {
                matrLev[i].push(j);
            }
            else if (i !== 0 && j === 0) {
                matrLev[i].push(i);
            }
            else {
                matrLev[i].push(-1);
            }
        }
    }
    

    let ans = calculate_Value(matrLev, firstLen, secondLen, firstWord, secondWord);
    time = performance.now() - time;
    console.log(time/1000);
    //console.log(matrLev);
    console.log("Distance of Levenstein by rec-matr: " + ans);
}

function findDistDamerLev() {
    let matrDamerLev = [];
    let firstWord = readlineSync.question("Input first word:");
    let secondWord = readlineSync.question("Input second word:");
    let firstLen = firstWord.length;
    let secondLen = secondWord.length;
    let time = performance.now();
    for (let i = 0; i <= secondLen; i++) {
        matrDamerLev.push([]);
        for (let j = 0; j <= firstLen; j++) {
            if (i === 0) {
                matrDamerLev[i].push(j);
            }
            if (i >= 1 && j === 0) {
                matrDamerLev[i].push(i);
            }
            if (i !== 0 && j !== 0) {
                let fElem = matrDamerLev[i][j - 1] + 1;
                let sElem = matrDamerLev[i - 1][j] + 1;
                let tElem = matrDamerLev[i - 1][j - 1];
                let flag = false;
                let fouElem = -1;
                if (i >= 1 && j >= 1 && secondWord[i - 1] === firstWord[j - 2] && secondWord[i - 2] === firstWord[j - 1]) {
                    fouElem = matrDamerLev[i - 2][j - 2] + 1;
                    flag = true;
                } 
                if (firstWord[j - 1] !== secondWord[i - 1]) {
                    tElem += 1;
                }
                if (flag === true) {
                    if (fouElem <= fElem && fouElem <= sElem && fouElem <= tElem) {
                        matrDamerLev[i].push(fouElem);
                    }
                }
                else if (fElem <= sElem && fElem <= tElem) {
                    matrDamerLev[i].push(fElem);
                }
                else if (sElem <= fElem && sElem <= tElem) {
                    matrDamerLev[i].push(sElem);
                }
                else if (tElem <= fElem && tElem <= sElem) {
                    matrDamerLev[i].push(tElem);
                }
            }
        }
    }
    time = performance.now() - time;
    console.log(time/1000);

    console.log(matrDamerLev);
    console.log("Distance of Damerau - Levenstein: " + matrDamerLev[secondLen][firstLen]);
}

findLevDist();
findLevDistRec();
findLevDistRecMatr();
findDistDamerLev();
