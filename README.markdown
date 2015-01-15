A SpAMM tree inside a contiguous memory chunk

# Introduction

This is an implementation of SpAMM inside a contiguous memory
chunk. This chunking allows us to keep a fine grained granularity at
the leaf level (much too fine for decent performance if allocated
non-contiguously) while improving memory access performance. As a neat
side effect, the chunks are already packed and "serialized" and can be
migrated as is to other nodes in an MPI/Charm++/... setup.

# Build Instructions

Simply run

~~~
cmake .
make
~~~

There are some tests, that are run with

~~~
make test
~~~

# Current build status

The current status of our test builds on Travis-ci is
[![Build Status](https://travis-ci.org/FreeON/spamm-chunk.svg)](https://travis-ci.org/FreeON/spamm-chunk).
