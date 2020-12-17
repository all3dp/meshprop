{
  "targets": [
    {
      "target_name": "meshprop",
      "sources": [ "lib/meshprop.cpp", "vcglib/wrap/ply/plylib.cpp" ],
      "include_dirs": [
        "./lib",
        "./vcglib",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "cflags!": [ '-fno-exceptions' ],
      "cflags_cc!": [ '-fno-exceptions' ],
      "conditions": [
        ['OS=="mac"', {
          "xcode_settings": { "GCC_ENABLE_CPP_EXCEPTIONS": "YES" }
        }]
      ]
    }
  ]
}
