# mulle-slug

#### 🐌 Creates URL slugs

Create a [slug](https://de.ryte.com/wiki/Slug) from some arbitrary text,
suitable for inclusion in a URL as a path or fragment.

#### What is a Slug?

A slug is a URL-safe representation of a page title, often used in web
development to create clean and readable URLs.
Slugs are typically all lowercase and replace spaces with hyphens, making them
more human-friendly than raw URL-encoded strings.
For example, the page title "A Beginner's Guide to Web Development" could have
the slug "a-beginners-guide-to-web-development". The term "slug" is derived
from the publishing industry, where it refers to a short, descriptive label for
an article or story. **mulle-slug** preserves case though.



| Release Version                                       | Release Notes  | AI Documentation
|-------------------------------------------------------|----------------|---------------
| ![Mulle kybernetiK tag](https://img.shields.io/github/tag/mulle-c/mulle-slug.svg) ![standard: C11](pix/c11.svg) ![apis: ansi](pix/apis-ansi.svg) ![memory: allocator](pix/memory-allocator.svg) ![threads: threadsafe](pix/thread-threadsafe.svg) [![Build Status](https://github.com/mulle-c/mulle-slug/workflows/CI/badge.svg)](//github.com/mulle-c/mulle-slug/actions) ![Coverage](https://img.shields.io/badge/coverage-100%25%C2%A0-2acf49) | [RELEASENOTES](RELEASENOTES.md) | [DeepWiki for mulle-slug](https://deepwiki.com/mulle-c/mulle-slug)




## Documentation & Guides

* [API Summary](asset/dox/api/toc)

## API

### `mulle_slugify`

```c
char *mulle_slugify(char *dst, size_t dst_len, char *src, size_t src_len);
```

This function creates a URL slug from the given source string `src` and stores
it in the destination buffer `dst`. The `dst_len` parameter specifies the size
of the destination buffer, and `src_len` specifies the length of the source
string. Pass `(size_t) -1` for `src_len` to use `strlen` on a NUL-terminated
source. Returns `dst` on success, `NULL` if `dst_len` is 0.

### `mulle_slugify_with_delimiter`

```c
char *mulle_slugify_with_delimiter(char *dst, size_t dst_len, char *src, size_t src_len, char delimiter);
```

This function is similar to `mulle_slugify`, but it allows you to specify a
custom delimiter character instead of the default hyphen `-`.

### `mulle_utf8_slugify`

```c
char *mulle_utf8_slugify(char *s);
```

Returns a `mulle_free`-able slugified copy of the NUL-terminated input string.
Returns `NULL` if `s` is `NULL`.

### `mulle_buffer_add_slugified_utf8data`

```c
void mulle_buffer_add_slugified_utf8data(struct mulle_buffer *buffer, struct mulle_utf8data data);
```

Appends the slugified form of `data` to an existing `mulle_buffer`.
This is the zero-malloc building block — use it when constructing larger
strings or HTML pages.

### Example Code

Here's an example of how to use the mulle-slug library:

```c
#include <stdio.h>
#include <string.h>
#include <mulle-slug/mulle-slug.h>

int main() {
    const char *input = "Take me home!";
    char output[256];

    mulle_slugify(output, sizeof(output), input, strlen(input));

    printf("Input: %s\n", input);
    printf("Slugified: %s\n", output);

    return 0;
}
```

This example demonstrates how to use the `mulle_slugify` function to create a
URL slug from the given input string. The output will be:

```
Input: Take me home!
Slugified: Take-me-home
```


### You are here

![Overview](overview.dot.svg)





## Add

### Add mulle-slug via mulle-core

mulle-slug is a component of the
[mulle-core](//github.com/mulle-core/mulle-core) library.
In your code include its umbrella header:

``` c
#include <mulle-core/mulle-core.h>
```

Add mulle-core to your `CMakeLists.txt` with
[FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html):

``` cmake
include( FetchContent)

set( MULLE__CORE_TAG "master" CACHE STRING "branch or tag to fetch mulle-core from")

FetchContent_Declare( MULLE__CORE
   GIT_REPOSITORY https://github.com/mulle-core/mulle-core.git
   GIT_TAG        "${MULLE__CORE_TAG}")
FetchContent_MakeAvailable( MULLE__CORE)

target_link_libraries( ${PROJECT_NAME} PUBLIC mulle-core)
```

Or add to your mulle-sde project with:

``` sh
mulle-sde add mulle-core/mulle-core
```




### Add mulle-slug as a cmake subproject

In your code include its header:

``` c
#include <mulle-slug/mulle-slug.h>
```

Add mulle-slug and its dependencies to your `CMakeLists.txt` with
[FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html):

``` cmake
include( FetchContent)

include_directories( SYSTEM "${CMAKE_BINARY_DIR}/include")

set( MULLE__C11_TAG "master" CACHE STRING "branch or tag to fetch mulle-c11 from")

FetchContent_Declare( MULLE__C11
   GIT_REPOSITORY https://github.com/mulle-c/mulle-c11.git
   GIT_TAG        "${MULLE__C11_TAG}")
FetchContent_MakeAvailable( MULLE__C11)

set( MULLE__ALLOCATOR_TAG "master" CACHE STRING "branch or tag to fetch mulle-allocator from")

FetchContent_Declare( MULLE__ALLOCATOR
   GIT_REPOSITORY https://github.com/mulle-c/mulle-allocator.git
   GIT_TAG        "${MULLE__ALLOCATOR_TAG}")
FetchContent_MakeAvailable( MULLE__ALLOCATOR)

set( MULLE__DATA_TAG "master" CACHE STRING "branch or tag to fetch mulle-data from")

FetchContent_Declare( MULLE__DATA
   GIT_REPOSITORY https://github.com/mulle-c/mulle-data.git
   GIT_TAG        "${MULLE__DATA_TAG}")
FetchContent_MakeAvailable( MULLE__DATA)

set( MULLE__UTF_TAG "master" CACHE STRING "branch or tag to fetch mulle-utf from")

FetchContent_Declare( MULLE__UTF
   GIT_REPOSITORY https://github.com/mulle-c/mulle-utf.git
   GIT_TAG        "${MULLE__UTF_TAG}")
FetchContent_MakeAvailable( MULLE__UTF)

set( MULLE__BUFFER_TAG "master" CACHE STRING "branch or tag to fetch mulle-buffer from")

FetchContent_Declare( MULLE__BUFFER
   GIT_REPOSITORY https://github.com/mulle-c/mulle-buffer.git
   GIT_TAG        "${MULLE__BUFFER_TAG}")
FetchContent_MakeAvailable( MULLE__BUFFER)

set( MULLE__UNICODE_TAG "master" CACHE STRING "branch or tag to fetch mulle-unicode from")

FetchContent_Declare( MULLE__UNICODE
   GIT_REPOSITORY https://github.com/mulle-c/mulle-unicode.git
   GIT_TAG        "${MULLE__UNICODE_TAG}")
FetchContent_MakeAvailable( MULLE__UNICODE)

set( MULLE__SLUG_TAG "master" CACHE STRING "branch or tag to fetch mulle-slug from")

FetchContent_Declare( MULLE__SLUG
   GIT_REPOSITORY https://github.com/mulle-c/mulle-slug.git
   GIT_TAG        "${MULLE__SLUG_TAG}")
FetchContent_MakeAvailable( MULLE__SLUG)

target_link_libraries( ${PROJECT_NAME} PUBLIC mulle-slug)
```

Or add to your mulle-sde project with:

``` sh
mulle-sde add github:mulle-c/mulle-slug
```

## Individual Install

Install all the prerequisites.

``` bash
PREFIX=/tmp/usr/local
BUILD_DIR="mulle-slug/build"

cmake -S "mulle-slug" -B "${BUILD_DIR}"    \
  -DCMAKE_BUILD_TYPE="Release"                  \
  -DCMAKE_INSTALL_PREFIX="${PREFIX}"            \
  -DCMAKE_PREFIX_PATH="${PREFIX}"               \
  -DCMAKE_C_FLAGS="-I"${PREFIX}"/include"       \
&& cmake --build "${BUILD_DIR}"  --parallel     \
&& cmake --install "${BUILD_DIR}"
```

## Acknowledgments

This is a C port of [C++ Slugify](https://github.com/thomasbrueggemann/cpp-slugify)
with a different, probably much faster, algorithm.

## Author

[Nat!](https://mulle-kybernetik.com/weblog) for Mulle kybernetiK  



