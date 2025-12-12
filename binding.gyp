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
      "cflags": ["-std=c++17"],
      "cflags_cc": ["-std=c++17"],
      "cflags!": [ "-fno-exceptions", "-fno-rtti" ],
      "cflags_cc!": [ "-fno-exceptions", "-fno-rtti" ],
      "conditions": [
        ['OS=="mac"', {
          "xcode_settings": {
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
            "GCC_ENABLE_CPP_RTTI": "YES",
            "OTHER_CPLUSPLUSFLAGS": [
              "-std=c++17"
            ]
          }
        }]
      ]
    }
  ]
}