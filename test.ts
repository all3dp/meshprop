/// <reference path="./typings/tsd.d.ts"/>

import mocha = require("mocha");
import assert = require("assert");

import meshprop = require('./index');

describe("meshprop tests", () => {

  it("get correct resuts for the fixture", (done) => {
    console.log(__dirname + "/fixture/snowman.stl");
    meshprop(__dirname + "/fixture/snowman.stl", (err, res) => {
      assert.equal(err, null);
      assert.deepEqual(res, {
        "volume" : 97177.8,
        "area" : 15730.4,
        "bbox" : {
          "x" : 71.054,
          "y" : 49.728,
          "z" : 95.002
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
