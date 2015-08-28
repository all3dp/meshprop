/// <reference path="./typings/tsd.d.ts"/>
var child_process = require('child_process');
function meshprop(filename, callback) {
    var cmd = 'meshprop ' + filename;
    child_process.exec(cmd, function (error, stdout, stderr) {
        if (!error) {
            callback(null, JSON.parse(stdout.toString()));
        }
        else {
            callback(new Error(stdout.toString()), null);
        }
    });
}
;
if (require.main === module) {
    meshprop('fixture/snowman.stl_', function (err, res) {
        console.log(err, res);
    });
}
module.exports = meshprop;
//# sourceMappingURL=index.js.map