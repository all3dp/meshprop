/// <reference path="./typings/tsd.d.ts"/>

import child_process = require('child_process');

function meshprop(filename, callback : (err : Error, res : string) => void) {
  var cmd = 'meshprop ' + filename;

  child_process.exec(cmd, (error, stdout, stderr) => {
    if (!error) {
      callback(null, JSON.parse(stdout.toString()));
    } else {
      callback(new Error(stdout.toString()), null);
    }
  });

};

export = meshprop;

// started with `$ node <FILENAME>`
if (require.main === module) {
  meshprop('fixture/snowman.stl_', (err, res) => {
    console.log(err, res);
  });
}
