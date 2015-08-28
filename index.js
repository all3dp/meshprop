/// <reference path="./typings/tsd.d.ts"/>
var meshprop = require('bindings')('meshprop');
if (require.main === module) {
    meshprop('fixture/snowman.stl', function (err, res) {
        console.log(err, res);
    });
}
module.exports = meshprop;
//# sourceMappingURL=index.js.map