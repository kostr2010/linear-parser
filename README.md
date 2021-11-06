# DESCRIPTION

implementation of linear parser for simple commands

`example.cpp` contains example use of this library. delete it if you want to yse this repo as the library for your project

# HOW TO BUILD

```
mkdir -p build && cd $_
cmake ..
make
```

# HOW TO RUN

from `build` directory: `./example`

# HOW TO MAINTAIN

`isa.h` file contains full description of available commands with their respective formats and mnemonics. in order to add your own commands, you can add lines to `isa.h` following the existing pattern. if you need to add more types / formats, you can totally do so. in oder to support new type, you would need to add new function, like `ParseOperandINT()` in `parser.cpp`. In order to add new format with existing types, you just need to write it down to ISA, codegen will do the rest
