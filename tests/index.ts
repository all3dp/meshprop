/// <reference path="../typings/tsd.d.ts"/>

import mocha = require("mocha");
import assert = require("assert");

import meshprop = require('../index');

describe("meshprop tests", () => {

  it("get correct resuts for the fixture", (done) => {
    meshprop(__dirname + "/fixture/snowman.stl", (err, res) => {
      assert.equal(err, null);
      assert.deepEqual(res, {
        "volume" : 97177.8125,
        "area" : 15730.4033203125,
        "bbox" : {
          "x" : 71.05400085449219,
          "y" : 49.72800064086914,
          "z" : 95.00199890136719
        }
      });
      done();
    });
  });

  it("damaged file", (done) => {
    meshprop("no-existing.stl", (err, res) => {
      assert.equal(res, null);
      assert.equal(err.message, "can't import mesh");
      done();
    });
  })
});
