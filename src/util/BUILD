load("//tools:build.bzl", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "singleton",
    hdrs = [
        "barrier.h",
        "singleton.h",
    ],
    deps = [
        "@com_google_absl//absl/synchronization",
    ],
)

cc_test(
    name = "singleton_test",
    timeout = "short",
    srcs = [
        "singleton_test.cc",
    ],
    deps = [
        ":singleton",
    ],
)

cc_library(
    name = "util",
    srcs = ["util.cc"],
    hdrs = [
        "util.h",
    ],
    deps = [
        "@boost//:algorithm",
        "@boost//:beast",
        "@boost//:filesystem",
        "@boost//:iostreams",
        "@com_github_fmtlib_fmt//:fmt",
        "@com_github_glog_glog//:glog",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/time",
        "@com_google_protobuf//:protobuf",
        "@openssl",
    ],
)

cc_test(
    name = "util_test",
    srcs = ["util_test.cc"],
    data = [
        "//test_data/config:config.json",
    ],
    deps = [
        ":util",
        "@com_github_glog_glog//:glog",
    ],
)

cc_library(
    name = "config",
    hdrs = ["config.h"],
    deps = [
        ":singleton",
        ":util",
        "//src/proto:cc_config",
        "@com_github_gflags_gflags//:gflags",
    ],
)

cc_test(
    name = "config_test",
    timeout = "short",
    srcs = ["config_test.cc"],
    data = [
        "//test_data/config:config.json",
    ],
    deps = [
        ":config",
    ],
)

cpplint()
