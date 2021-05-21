# File embedder
Usage is `embedfiles [file to embed...] [-l {c}] [-o {outfile}]`. To specify another language use the `-l` option (C is the only  lang supported as of now). It creates a new file in the specified language and puts a byte array of the inputfile in. Example output: 
<details>
  <summary>Example Output</summary>
  in.txt: 
  
  ```
  Hello World!
  ```
  
  out.c: 
  
  ```
  #include <stdlib.h>
  const char in.txt[] = {
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 
    0x64, 0x21, 0x0a, 
  };
  const size_t in.txt_len = sizeof(in.txt);
  ```
  
  </details>

# Building
This project requires no libraries other than glibc or other implementations of libc. Run `mkdir build && cd build && cmake ..` and then `make`. This will produce the `èmbedfiles` binary.

# Contributing
You can add new languages if you like. Just open a pull request!

# Copyright
The other members of the cro-pkg organization, and me, [legendary-cookie](https://github.com/legendary-cookie/) own all rights for the code contained in this repository. You are allowed to contribute, but not redistribute.
