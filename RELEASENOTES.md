## 0.2.0



* map generation step now also sets `DYLD_LIBRARY_PATH` so generated slugs work on macOS




feature: add Unicode decomposition and new slugify APIs

* new ``mulle_slugify()`` and ``mulle_slugify_with_delimiter()`` convenience functions that write into a caller-provided buffer
* new ``mulle_utf8_slugify_utf8()`` and ``mulle_buffer_add_utf8_slugified_utf8data()`` pass non-transliterable characters (CJK, Arabic, etc.) through as UTF-8 instead of dropping them
* new ``mulle_buffer_add_slugified_utf8data_with_delimiter()`` for custom delimiter characters
* transliteration now uses a Unicode canonical/compatibility decomposition table generated from UnicodeData.txt, covering far more characters (Latin, Cyrillic, Greek, etc.)
* combining marks (e.g. decomposed accents) are stripped, improving handling of precomposed/decomposed input
* output for ©/® changes from "(c)"/"(r)" to "c"/"r"



* BSD 3-clause license headers added to all .c and .h source files
* API documentation restructured with dedicated toc index


### 0.1.1

Various small improvements
