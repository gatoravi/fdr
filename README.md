#FDR

This repo applies the Benjamini Hochberg procedure for controlling
the FDR. This operates on a C++ vector of floats which represent
the p-values from hypotheses tests.

```
    mkdir build && cd build
    cmake ..
    make
    ./test-bh-fdr
```
