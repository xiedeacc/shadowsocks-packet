workspace(name = "shadowsocks-packet")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "bazel_skylib",
    remote = "git@github.com:bazelbuild/bazel-skylib.git",
    tag = "1.7.1",
)

git_repository(
    name = "platforms",
    remote = "git@github.com:bazelbuild/platforms.git",
    tag = "0.0.10",
)

git_repository(
    name = "bazel_gazelle",
    remote = "git@github.com:bazelbuild/bazel-gazelle.git",
    tag = "v0.37.0",
)

git_repository(
    name = "bazel_features",
    remote = "git@github.com:bazel-contrib/bazel_features.git",
    tag = "v1.12.0",
)

git_repository(
    name = "rules_cc",
    remote = "git@github.com:bazelbuild/rules_cc.git",
    tag = "0.0.9",
)

git_repository(
    name = "rules_foreign_cc",
    remote = "git@github.com:bazelbuild/rules_foreign_cc.git",
    tag = "0.10.1",
)

git_repository(
    name = "rules_proto",
    remote = "git@github.com:bazelbuild/rules_proto.git",
    tag = "6.0.0",
)

git_repository(
    name = "rules_perl",
    remote = "git@github.com:bazelbuild/rules_perl.git",
    tag = "0.2.3",
)

git_repository(
    name = "rules_python",
    remote = "git@github.com:bazelbuild/rules_python.git",
    tag = "0.33.0",
)

git_repository(
    name = "rules_java",
    remote = "git@github.com:bazelbuild/rules_java.git",
    tag = "7.6.1",
)

git_repository(
    name = "build_bazel_rules_swift",
    remote = "git@github.com:bazelbuild/rules_swift.git",
    tag = "1.18.0",
)

git_repository(
    name = "io_bazel_rules_go",
    remote = "git@github.com:bazelbuild/rules_go.git",
    tag = "v0.48.0",
)

git_repository(
    name = "rules_pkg",
    remote = "git@github.com:bazelbuild/rules_pkg.git",
    tag = "1.0.0",
)

git_repository(
    name = "contrib_rules_jvm",
    remote = "git@github.com:bazel-contrib/rules_jvm.git",
    tag = "v0.27.0",
)

git_repository(
    name = "rules_jvm_external",
    remote = "git@github.com:bazelbuild/rules_jvm_external.git",
    tag = "6.1",
)

git_repository(
    name = "io_bazel_rules_docker",
    remote = "git@github.com:bazelbuild/rules_docker.git",
    tag = "v0.25.0",
)

git_repository(
    name = "apple_rules_lint",
    remote = "git@github.com:apple/apple_rules_lint.git",
    tag = "0.3.2",
)

git_repository(
    name = "build_bazel_rules_apple",
    remote = "git@github.com:bazelbuild/rules_apple.git",
    tag = "3.5.1",
)

git_repository(
    name = "build_bazel_apple_support",
    remote = "git@github.com:bazelbuild/apple_support.git",
    tag = "1.15.1",
)

new_git_repository(
    name = "cpplint",
    build_file = "//bazel_script:cpplint.BUILD",
    commit = "7b88b68187e3516540fab3caa900988d2179ed24",
    remote = "git@github.com:cpplint/cpplint.git",
)

git_repository(
    name = "jemalloc",
    commit = "14397d2ebc59298bdabb11b31a1366aed380ac81",
    remote = "git@github.com:xiedeacc/jemalloc.git",
)

#new_git_repository(
#name = "lzma",
#build_file = "//bazel_script:xz.BUILD",
#remote = "git@github.com:tukaani-project/xz.git",
#tag = "v5.6.2",
#)

git_repository(
    name = "zlib",
    commit = "50c820653b6f0c93e4d9da3141f946a98a113fd0",
    remote = "git@github.com:xiedeacc/zlib.git",
)

git_repository(
    name = "org_bzip_bzip2",
    commit = "67a2430bf9f180e50c2bc50bb1fcc69155105328",
    remote = "git@github.com:xiedeacc/bzip2.git",
)

git_repository(
    name = "lz4",
    commit = "72b88d853b968827356394ea25b902adf8d707d0",
    remote = "git@github.com:xiedeacc/lz4.git",
)

#git_repository(
#name = "com_github_facebook_zstd",
#remote = "git@github.com:xiedeacc/zstd.git",
#commit = "df71f5eeadfacb8ac5ec139ea8b274a23b12dd0c",
#)

http_archive(
    name = "openssl",
    build_file = "//bazel_script:openssl.BUILD",
    repo_mapping = {
        "@com_github_madler_zlib": "@zlib",
    },
    sha256 = "e2f8d84b523eecd06c7be7626830370300fbcc15386bf5142d72758f6963ebc6",
    strip_prefix = "openssl-1.1.1u",
    urls = [
        "https://github.com/openssl/openssl/releases/download/OpenSSL_1_1_1u/openssl-1.1.1u.tar.gz",
    ],
)

git_repository(
    name = "libsodium",
    commit = "c9244999525f980dd810ae9bb5c542aeeac92ecc",
    remote = "git@github.com:xiedeacc/libsodium.git",
)

git_repository(
    name = "com_github_libevent_libevent",
    commit = "e017ba6d1001f1d91954391afc8a1324a90df63a",
    remote = "git@github.com:xiedeacc/libevent.git",
)

git_repository(
    name = "com_github_fmtlib_fmt",
    commit = "6e54c9e689f8d4fff46e791043441cb3e45c057b",
    remote = "git@github.com:xiedeacc/fmt.git",
)

git_repository(
    name = "com_github_gflags_gflags",
    remote = "git@github.com:gflags/gflags.git",
    tag = "v2.2.2",
)

git_repository(
    name = "com_github_glog_glog",
    remote = "git@github.com:google/glog.git",
    tag = "v0.7.1",
)

new_git_repository(
    name = "com_github_google_snappy",
    build_file = "//bazel_script:snappy.BUILD",
    remote = "git@github.com:google/snappy.git",
    tag = "1.1.8",
)

git_repository(
    name = "com_google_absl",
    remote = "git@github.com:abseil/abseil-cpp.git",
    tag = "20230125.3",
)

git_repository(
    name = "com_google_googletest",
    remote = "git@github.com:google/googletest.git",
    tag = "v1.13.0",
)

git_repository(
    name = "com_github_google_re2",
    commit = "9dc7ae7b52a17b75e3f9249ea85ba578bf42f255",
    remote = "git@github.com:google/re2.git",
)

git_repository(
    name = "double-conversion",
    commit = "29e61b7f6ed92c8809d78f96c7cb59cd293adce8",
    remote = "git@github.com:google/double-conversion.git",
)

git_repository(
    name = "libunwind",
    commit = "2cfcc7ad6cefc777ea5c2ae861f089c2391166d0",
    remote = "git@github.com:xiedeacc/libunwind.git",
)

git_repository(
    name = "libdwarf",
    commit = "0da1734dfafcf0756c14e8ae6ee257310ed1c9b5",
    remote = "git@github.com:xiedeacc/libdwarf.git",
)

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "45ed6bf51f659c7db830fd15ddd4495dadc5afd1",
    remote = "git@github.com:nelhage/rules_boost.git",
    repo_mapping = {
        "@boringssl": "@openssl",
    },
)

http_archive(
    name = "curl",
    build_file = "//bazel_script:curl.BUILD",
    sha256 = "01ae0c123dee45b01bbaef94c0bc00ed2aec89cb2ee0fd598e0d302a6b5e0a98",
    strip_prefix = "curl-7.69.1",
    urls = [
        "https://github.com/curl/curl/releases/download/curl-7_69_1/curl-7.69.1.tar.gz",
    ],
)

git_repository(
    name = "c-ares",
    commit = "c520142b68abf7762aa9d9c58258a2e82d3ec155",
    remote = "git@github.com:xiedeacc/c-ares.git",
)

new_git_repository(
    name = "nacos_sdk",
    build_file = "//bazel_script:nacos_sdk.BUILD",
    commit = "c73bf483ca32ee7edc2eaa215268b84144493f62",
    remote = "git@github.com:xiedeacc/nacos-sdk-cpp.git",
    repo_mapping = {
        "@com_github_curl_curl": "@curl",
        "@com_github_madler_zlib": "@zlib",
    },
)

#new_git_repository(
#name = "gperftools",
#build_file = "//bazel_script:gperftools.BUILD",
#remote = "git@github.com:gperftools/gperftools.git",
#tag = "gperftools-2.10",
#)

new_git_repository(
    name = "com_github_google_leveldb",
    build_file = "//bazel_script:leveldb.BUILD",
    remote = "git@github.com:google/leveldb.git",
    tag = "leveldb-1.23",
)

new_git_repository(
    name = "com_github_google_crc32c",
    build_file = "//bazel_script:crc32c.BUILD",
    remote = "git@github.com:google/crc32c.git",
    tag = "1.1.2",
)

#git_repository(
#name = "brpc",
#remote = "git@github.com:apache/brpc.git",
#repo_mapping = {
#"@com_github_google_glog": "@com_github_glog_glog",
#"@com_github_curl_curl": "@curl",
#"@com_github_madler_zlib": "@zlib",
#},
#tag = "1.3.0",
#)

#new_git_repository(
#name = "swig",
#build_file = "//bazel_script:swig.BUILD",
#patch_args = ["-p1"],
#patches = ["//bazel_script:swig.patch"],
#remote = "git@github.com:swig/swig.git",
#tag = "v4.1.1",
#)

new_git_repository(
    name = "pcre2",
    build_file = "//bazel_script:pcre2.BUILD",
    remote = "git@github.com:PCRE2Project/pcre2.git",
    tag = "pcre2-10.42",
)

git_repository(
    name = "com_google_benchmark",
    remote = "git@github.com:google/benchmark.git",
    tag = "v1.8.1",
)

new_git_repository(
    name = "spdlog",
    build_file = "//bazel_script:spdlog.BUILD",
    remote = "git@github.com:gabime/spdlog.git",
    tag = "spdlog-1.12.0",
)

new_git_repository(
    name = "rapidjson",
    build_file = "//bazel_script:rapidjson.BUILD",
    commit = "f9d53419e912910fd8fa57d5705fa41425428c35",
    remote = "git@github.com:Tencent/rapidjson.git",
)

git_repository(
    name = "hedron_compile_commands",
    commit = "a14ad3a64e7bf398ab48105aaa0348e032ac87f8",
    remote = "git@github.com:hedronvision/bazel-compile-commands-extractor.git",
)

load("@bazel_skylib//lib:versions.bzl", "versions")

versions.check("7.2.0")

load("@bazel_features//:deps.bzl", "bazel_features_deps")
load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")
load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")
load("@rules_java//java:repositories.bzl", "rules_java_dependencies", "rules_java_toolchains")
load("@rules_perl//perl:deps.bzl", "perl_register_toolchains")
load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies")
load("@rules_proto//proto:toolchains.bzl", "rules_proto_toolchains")
load("@rules_python//python:repositories.bzl", "py_repositories")

bazel_features_deps()

rules_foreign_cc_dependencies()

rules_java_dependencies()

py_repositories()

go_rules_dependencies()

rules_pkg_dependencies()

rules_proto_dependencies()

boost_deps()

rules_proto_toolchains()

rules_java_toolchains()

go_register_toolchains(version = "1.18")

perl_register_toolchains()

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

load("@hedron_compile_commands//:workspace_setup_transitive.bzl", "hedron_compile_commands_setup_transitive")

hedron_compile_commands_setup_transitive()

load("@hedron_compile_commands//:workspace_setup_transitive_transitive.bzl", "hedron_compile_commands_setup_transitive_transitive")

hedron_compile_commands_setup_transitive_transitive()

load("@hedron_compile_commands//:workspace_setup_transitive_transitive_transitive.bzl", "hedron_compile_commands_setup_transitive_transitive_transitive")

hedron_compile_commands_setup_transitive_transitive_transitive()

####### JVM #######
load("@rules_jvm_external//:repositories.bzl", "rules_jvm_external_deps")

rules_jvm_external_deps()

load("@rules_jvm_external//:setup.bzl", "rules_jvm_external_setup")

rules_jvm_external_setup()

load("@rules_jvm_external//:defs.bzl", "maven_install")

JUNIT_PLATFORM_VERSION = "1.9.2"

JUNIT_JUPITER_VERSION = "5.9.2"

maven_install(
    artifacts = [
        "net.java.dev.jna:jna:aar:5.13.0",
        "com.google.truth:truth:0.32",
        "org.junit.platform:junit-platform-launcher:%s" % JUNIT_PLATFORM_VERSION,
        "org.junit.platform:junit-platform-reporting:%s" % JUNIT_PLATFORM_VERSION,
        "org.junit.jupiter:junit-jupiter-api:%s" % JUNIT_JUPITER_VERSION,
        "org.junit.jupiter:junit-jupiter-params:%s" % JUNIT_JUPITER_VERSION,
        "org.junit.jupiter:junit-jupiter-engine:%s" % JUNIT_JUPITER_VERSION,
    ],
    repositories = [
        "https://maven.aliyun.com/repository/central",
    ],
)

load("@contrib_rules_jvm//:repositories.bzl", "contrib_rules_jvm_deps")

contrib_rules_jvm_deps()

load("@contrib_rules_jvm//:setup.bzl", "contrib_rules_jvm_setup")

contrib_rules_jvm_setup()
