# Get 3D mesh properties

This NPM-module will calculate the *volume*, *area*, and *boundingbox* of a 3d model.
The algorithm is written in *C++*. And is using internaly the VCG library http://vcg.isti.cnr.it/vcglib/index.html

[![Build Status](https://travis-ci.org/dreampulse/meshprop.svg?branch=master)](https://travis-ci.org/dreampulse/meshprop)

## Supported file formats
PLY, STL, OFF, OBJ, 3DS, COLLADA, PTX, V3D, PTS, APTS, XYZ, GTS, TRI, ASC, X3D, X3DV, VRML, ALN

## Dependencies
* qmake is required to build this module

e.g.:
```
sudo apt-get install libqt4-dev qt4-qmake
```

Usage
```
var meshprop = require('meshprop');

meshprop('path-to-my-mesh.stl', function(err, props) {
  console.log(props);
});
```

Example Result
```
{
  "volume" : 97177.8,
  "area" : 15730.4,
  "bbox" : {
    "x" : 71.054,
    "y" : 49.728,
    "z" : 95.002
  }
}
```
