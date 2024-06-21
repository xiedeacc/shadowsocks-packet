load("//tools:build.bzl", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "test_main",
    srcs = ["test_main.cc"],
    deps = [
        "//src/util",
        "@com_github_gflags_gflags//:gflags",
        "@com_google_googletest//:gtest",
    ],
)

cpplint()
