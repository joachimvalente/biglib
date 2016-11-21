cc_library(
    name = "main",
    srcs = glob(
        [
            "google*/src/*.cc",
        ],
        exclude = glob([
            "google*/src/*-all.cc",
            "googlemock/src/gmock_main.cc",
        ]),
    ),
    hdrs = glob(["*/include/**/*.h"]),
    includes = [
        "googlemock/",
        "googlemock/include",
        "googletest/",
        "googletest/include",
    ],
    textual_hdrs = ["googletest/src/gtest-internal-inl.h"],
    visibility = ["//visibility:public"],
)
