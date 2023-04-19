# mulle-slug

#### 🐌 Creates URL slugs

Create a [slug](https://de.ryte.com/wiki/Slug) from some arbitrary text,
suitable for inclusion in a URL as a path or fragment. So the string
"## Take me home!" as a slug will be "Take-me-home".
| Release Version                                       | Release Notes
|-------------------------------------------------------|--------------
| ![Mulle kybernetiK tag](https://img.shields.io/github/tag/mulle-c/mulle-slug.svg?branch=release) [![Build Status](https://github.com/mulle-c/mulle-slug/workflows/CI/badge.svg?branch=release)](//github.com/mulle-c/mulle-slug/actions)| [RELEASENOTES](RELEASENOTES.md) |






### You are here

![Overview](overview.dot.svg)





## Add

Use [mulle-sde](//github.com/mulle-sde) to add mulle-slug to your project:

``` sh
mulle-sde add github:mulle-c/mulle-slug
```

To only add the sources of mulle-slug with dependency
sources use [clib](https://github.com/clibs/clib):


``` sh
clib install --out src/mulle-c mulle-c/mulle-slug
```

Add `-isystem src/mulle-c` to your `CFLAGS` and compile all the sources that were downloaded with your project.


## Install

### Install with mulle-sde

Use [mulle-sde](//github.com/mulle-sde) to build and install mulle-slug and all dependencies:

``` sh
mulle-sde install --prefix /usr/local \
   https://github.com/mulle-c/mulle-slug/archive/latest.tar.gz
```

### Manual Installation

Install the requirements:

| Requirements                                 | Description
|----------------------------------------------|-----------------------
| [mulle-utf](https://github.com/mulle-c/mulle-utf)             | 🔤 UTF8-16-32 analysis and manipulation library
| [mulle-buffer](https://github.com/mulle-c/mulle-buffer)             | ↗️ A growable C char array and also a stream

Install **mulle-slug** into `/usr/local` with [cmake](https://cmake.org):

``` sh
cmake -B build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DCMAKE_PREFIX_PATH=/usr/local \
      -DCMAKE_BUILD_TYPE=Release &&
cmake --build build --config Release &&
cmake --install build --config Release
```

## Acknowledgments

This is a C port of [C++ Slugify](https://github.com/thomasbrueggemann/cpp-slugify)
with a different, probably much faster, algorithm.

## Author

[Nat!](https://mulle-kybernetik.com/weblog) for Mulle kybernetiK



