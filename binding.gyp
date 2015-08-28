{
  "targets": [
    {
      "target_name": "meshprop",
      "sources": [ "meshprop.cpp", "vcglib/wrap/ply/plylib.cpp" ],
      "include_dirs": [".", "./vcglib"],
      "cflags!": [ '-fno-exceptions' ],
            "cflags_cc!": [ '-fno-exceptions' ],
            "conditions": [
                ['OS=="mac"', {
                    "xcode_settings": {
                    "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
                    }
                }]
            ]
    }
  ]
}
