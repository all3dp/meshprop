import { createRequire } from 'node:module';
const require = createRequire(import.meta.url);

const meshprop = require('./build/Release/meshprop');
export default meshprop;