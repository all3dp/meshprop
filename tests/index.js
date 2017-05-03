/// <reference path="../typings/tsd.d.ts"/>
var assert = require("assert");
var meshprop = require('../index');
describe("meshprop tests", function () {
    it("get correct resuts for the fixture", function (done) {
        meshprop.parse(__dirname + "/fixture/snowman.stl", function (err, res) {
            assert.equal(err, null);
            assert.deepEqual(res, {
                "volume": 97177.8125,
                "area": 15730.4033203125,
                "bbox": {
                    "x": 71.05400085449219,
                    "y": 49.72800064086914,
                    "z": 95.00199890136719
                }
            });
            done();
        });
    });
    it("damaged file", function (done) {
        meshprop.parse("no-existing.stl", function (err, res) {
            assert.equal(res, null);
            assert.equal(err.message, "can't import mesh");
            done();
        });
    });
});
//# sourceMappingURL=index.js.map