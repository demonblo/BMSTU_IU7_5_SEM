"use strict"

let expansion = ".txt";
let fs = require("fs");

function check_out(folder, spaces) {
    let arr = fs.readdirSync(folder);
    for(let i = 0; i < arr.length; i++) {
        if (arr[i].includes(expansion)) {
            let fileName = folder + "/" + arr[i];
            let contentString = fs.readFileSync(fileName, "utf8");
            if (contentString.length <= 10) {
                console.log(spaces + arr[i]);
            }
        }
        if (!arr[i].includes(expansion) && arr[i] != ".DS_Store" && !(arr[i].includes(".js"))) {
            console.log(spaces + arr[i]);
            let nextDir = "" + folder + "/" + arr[i];
            check_out(nextDir, spaces + "    ");
        }    
    }
}

console.log("task_04_01");
check_out("./task_04_01", "    ");