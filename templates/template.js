'use strict';

class Template {
  constructor () {
  }

  processData (input) {
  }

  solveAll () {
  }
};

const tem = new Template();
process.stdin.resume();
process.stdin.setEncoding("ascii");
const _arrInput = [];
process.stdin.on("data", function (input) {
  _arrInput.push(input);
});
process.stdin.on("end", function () {
  tem.processData(_arrInput.join(''));
  tem.solveAll();
});
