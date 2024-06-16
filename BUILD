load("@bazel_output_base_util//:defs.bzl", "OUTPUT_BASE")
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")
load("@rules_compdb//:defs.bzl", "compilation_database")

package(default_visibility = ["//visibility:public"])

exports_files(["CPPLINT.cfg"])

refresh_compile_commands(
    name = "refresh_compile_commands",
    targets = {
        "//...": "",
        #"//:my_output_1": "--important_flag1 --important_flag2=true",
    },
)

compilation_database(
    name = "compdb",
    # OUTPUT_BASE is a dynamic value that will vary for each user workspace.
    # If you would like your build outputs to be the same across users, then
    # skip supplying this value, and substitute the default constant value
    # "__OUTPUT_BASE__" through an external tool like `sed` or `jq` (see
    # below shell commands for usage).
    output_base = OUTPUT_BASE,
    targets = [
        "//src/util",
    ],
)
