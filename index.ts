/// <reference path="./typings/tsd.d.ts"/>

import child_process = require('child_process');

function meshprop(filename, callback : (err : Error, res : string) => void) {

  child_process.exec(__dirname + '/meshprop ' + filename, (error, stdout, stderr) => {
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
  meshprop('fixture/snowman.stl', (err, res) => {
    console.log(err, res);
  });
}
