load("//tools:build.bzl", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "misc",
    srcs = [
    ],
    hdrs = [
        "misc.h",
        "uthash.h",
    ],
    deps = [
        "@com_google_absl//absl/synchronization",
    ],
)

cc_library(
    name = "log",
    hdrs = [
        "log.h",
    ],
    deps = [
        "@com_google_absl//absl/synchronization",
    ],
)

cc_library(
    name = "net",
    srcs = [
        "net.c",
    ],
    hdrs = [
        "net.h",
    ],
    deps = [
        ":log",
        ":misc",
        "@com_google_absl//absl/synchronization",
    ],
)

cc_library(
    name = "dns",
    srcs = [
        "dns.c",
    ],
    hdrs = [
        "dns.h",
    ],
    copts = [
        "-std=c99",
    ],
    deps = [
        ":log",
        ":misc",
        ":net",
        "@com_google_absl//absl/synchronization",
    ],
)

cc_library(
    name = "opt",
    srcs = [
        "opt.c",
    ],
    hdrs = [
        "opt.h",
    ],
    deps = [
        ":misc",
        ":net",
        "@com_google_absl//absl/synchronization",
    ],
)

cc_library(
    name = "ipset",
    srcs = [
        "ipset.c",
        "nl.c",
    ],
    hdrs = [
        "ipset.h",
        "nl.h",
    ],
    copts = [
        "-std=c99",
    ],
    deps = [
        ":log",
        ":misc",
        ":net",
        ":opt",
        "@com_google_absl//absl/synchronization",
    ],
)

cc_library(
    name = "dnl",
    srcs = [
        "dnl.c",
    ],
    hdrs = [
        "dnl.h",
    ],
    copts = [
        "-std=c99",
    ],
    deps = [
        ":dns",
        ":ipset",
        ":log",
        ":misc",
        ":net",
        "@com_google_absl//absl/synchronization",
    ],
)

cc_binary(
    name = "china_dns",
    srcs = [
        "main.c",
    ],
    defines = [
        "BOOST_THREAD_BUILD_LIB=1",
        "BOOST_THREAD_PLATFORM_PTHREAD",
        "BOOST_THREAD_POSIX",
        "BOOST_THREAD_USES_CHRONO",
        "BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION=1",
        "BOOST_THREAD_PROVIDES_EXECUTORS=1",
        "BOOST_THREAD_USES_MOVE=1",
        "GOOGLE_LOGGING",
    ],
    linkopts = [
        "-pthread",
    ],
    linkstatic = 1,
    deps = [
        ":dnl",
        "@boost//:thread",
    ],
)

cpplint()
