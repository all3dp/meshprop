import { fileURLToPath } from 'node:url';
import { dirname } from 'node:path';
import assert from 'assert';
import meshprop from '../index.js';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

describe("meshprop tests", function () {
    it("should get correct results for the fixture", function (done) {
        meshprop.parse(__dirname + "/fixture/snowman.stl", function (err, res) {
            assert.strictEqual(err, null);
            assert.deepStrictEqual(res, {
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

    it("should throw error for damaged file", function (done) {
        meshprop.parse("no-existing.stl", function (err, res) {
            assert.strictEqual(res, null);
            assert.strictEqual(err.message, "Can't import mesh");
            done();
        });
    });
});
