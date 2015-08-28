/// <reference path="./typings/tsd.d.ts"/>
var assert = require("assert");
var meshprop = require('./index');
describe("meshprop tests", function () {
    it("get correct resuts for the fixture", function (done) {
        meshprop("fixture/snowman.stl", function (err, res) {
            assert.equal(err, null);
            assert.deepEqual(res, {
                "volume": 97177.8,
                "area": 15730.4,
                "bbox": {
                    "x": 71.054,
                    "y": 49.728,
                    "z": 95.002
                }
            });
            done();
        });
    });
    it("damaged file", function (done) {
        meshprop("no-existing.stl", function (err, res) {
            assert.equal(res, null);
            assert.equal(err.message, "can't import mesh");
            done();
        });
    });
});
//# sourceMappingURL=test.js.map