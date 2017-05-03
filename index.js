/// <reference path="./typings/tsd.d.ts"/>
var meshprop = require('bindings')('meshprop');
// started with `$ node <FILENAME>`
if (require.main === module) {
    meshprop('tests/fixture/snowman.stl', function (err, res) {
        console.log(err, res);
    });
}
module.exports = meshprop;
//# sourceMappingURL=index.js.map