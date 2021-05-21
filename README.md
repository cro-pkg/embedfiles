# File embedder
Usage is `embedfiles [file to embed...] [-l {c}] [-o {outfile}]`. To specify another language use the `-l` option (C is the only  lang supported as of now).

# Building
This project requires no libraries other than glibc or other implementations of libc. Run `mkdir build && cd build && cmake ..` and then `make`. This will produce the `èmbedfiles` binary.

# Contributing
You can add new languages if you like. Just open a pull request!

# Copyright
The other members of the cro-pkg organization, and me, [legendary-cookie](https://github.com/legendary-cookie/) own all rights for the code contained in this repository. You are allowed to contribute, but not redistribute.
