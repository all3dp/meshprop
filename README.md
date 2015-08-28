# Get Properties of your 3D mesh

This NPM-module will calculate the *volume*, *area*, and *boundingbox* of a 3d model.
The algorithm is written in *C++*. And is using internaly the VCG library http://vcg.isti.cnr.it/vcglib/index.html


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
