const testAddon = require('../build/Release/napi-medium.node');

const user = new testAddon.UserEntityWrap('oleg094', 21)
console.log(testAddon.getUser());


module.exports = testAddon;
