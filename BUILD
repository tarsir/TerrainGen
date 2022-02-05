# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "libraries",
  srcs = ["map.cpp", "voronoi.cpp"],
  hdrs = ["map.h"]
  # deps = ["map.h"],
)

cc_binary(
  name = "peru",
  srcs = ["main.cpp"],
  copts = [],
  deps = [":libraries"]
)