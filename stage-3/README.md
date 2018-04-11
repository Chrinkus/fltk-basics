# Stage 3
### Break out components into header and source files

There is little added here to the implementations, just separating code into modules. Once again the attention is placed on constructing a working Makefile.

One new detail is the use of header guards:
```c++
#ifndef SHAPE_H
#define SHAPE_H

// Class header

#endif  /* SHAPE_H */
```
These allow multiple files to include the same headers with out throwing linker errors.
