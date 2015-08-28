/// <reference path="./typings/tsd.d.ts"/>

var meshprop = require('bindings')('meshprop');

export = meshprop;

// started with `$ node <FILENAME>`
if (require.main === module) {

  meshprop('fixture/snowman.stl', (err, res) => {
    console.log(err, res);
  });
}
