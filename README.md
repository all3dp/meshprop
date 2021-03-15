[![Meshprop Release Workflow](https://github.com/all3dp/meshprop/actions/workflows/deploy.yml/badge.svg)](https://github.com/all3dp/meshprop/actions/workflows/deploy.yml)

# Get 3D mesh properties

This NPM-module will calculate the *volume*, *area*, and *boundingbox* of a 3d model.
The algorithm is written in *C++*. And is using internaly the VCG library http://vcg.isti.cnr.it/vcglib/index.html

## Supported file formats
Supported by VCG library: PLY, STL, OFF, OBJ, 3DS, COLLADA, PTX, V3D, PTS, APTS, XYZ, GTS, TRI, ASC, X3D, X3DV, VRML, ALN

Works most reliable with STL and PLY, other formats might experience problems with parsing geometries.

Usage
```
var meshprop = require('meshprop');

meshprop.parse('path-to-my-mesh.stl', function(err, props) {
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
