'use strict';

const execSync = require('child_process').execSync;

function useCmd(s) {
    const options = {encoding: 'utf8'};
    const cmd = s.toString();
    const answer = execSync(cmd, options);
    return answer.toString();
}

function getFact(num) {
    const command = `node fact.js ${num}`;
    return  parseInt(useCmd(command));
}

const args = process.argv.slice(2);
for (const num of args) {
    console.log(`${num}! = ${getFact(num)}`);
}

