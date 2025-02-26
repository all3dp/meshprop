import { createRequire } from 'node:module';
const require = createRequire(import.meta.url);

export const meshprop = require('./build/Release/meshprop');