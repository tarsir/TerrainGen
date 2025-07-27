# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library

cc_library(
  name = "libraries",
  srcs = ["src/map.cpp", "src/voronoi.cpp"],
  hdrs = ["src/map.h"],
  deps = ["@nlohmann_json//:json"]
)

cc_binary(
  name = "peru",
  srcs = ["src/main.cpp"],
  copts = [],
  deps = [":libraries"]
)

alias(
    name = "compile_commands",
    actual = "@wolfd_bazel_compile_commands//:generate_compile_commands",
)