# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library

cc_library(
  name = "libraries",
  srcs = glob(["src/*.cpp"], exclude=["src/main.cpp"]),
  hdrs = glob(["src/*.h"]),
  deps = ["@nlohmann_json//:json"]
)

cc_binary(
  name = "peru",
  srcs = ["src/main.cpp"],
  copts = [],
  deps = [":libraries"],
  data = ["config.json"]
)

alias(
    name = "compile_commands",
    actual = "@wolfd_bazel_compile_commands//:generate_compile_commands",
)
