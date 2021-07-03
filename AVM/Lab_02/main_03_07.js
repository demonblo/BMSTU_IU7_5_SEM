"use strict"

let fs = require("fs");
let node_0 = {name:"zero", left:null, right:null};
let node_1 = {name:"one", left:node_0, right:null};
let node_2 = {name:"two", left:node_1, right:null};
let node_3 = {name:"three", left:null, right:null};
let node_4 = {name:"four", left:null, right:null};
let node_5 = {name:"five", left:node_2, right:node_3};
let node_6 = {name:"six", left:node_4, right:node_0};
let node_7 = {name:"seven", left:node_5, right:node_6};

fs.writeFileSync("input_03_07.txt", JSON.stringify(node_7));
const tree = JSON.parse(fs.readFileSync("input_03_07.txt", "utf8"));
let max_branch = "";

function find_longest_branch(link, branch) {
    branch += link.name + " ";
    if (branch > max_branch) {
        max_branch = branch;
    }
    if(link.right != null) {
        find_longest_branch(link.right, branch);
    }
    if(link.left != null) {
        find_longest_branch(link.left, branch);
    }
}

find_longest_branch(tree, "");
console.log("The longest branch: " + max_branch);

