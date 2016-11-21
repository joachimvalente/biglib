cc_library(
    name = "vector",
    hdrs = ["vector.h"],
)

cc_test(
    name = "vector_test",
    srcs = ["vector_test.cc"],
    copts = ["-Igoogletest/include"],
    deps = [
        ":vector",
        "@gtest//:main"
    ],
)
