# Terrain Generators

This repo contains some terrain generation examples in C++. This project isn't really intended to
become a full-featured product or anything, I just thought it'd be a cool, kinda useful project
to get some more practice with C++ and Bazel.

## Usage

This project currently requires Bazel, which you can get with Bazelisk, by installing Bazel
directly, or through something like `mise`. As long as you have Bazel, it will download the
dependencies in the build process.

```sh
bazel run //:generate
```

The repo includes a basic `config.json` that allows setting the parameters for the generation. Right
now all the properties should be self-explanatory.

## Features

- Configurable generation
- JSON export
