# image_parser
read and parse image file, include format .bin, .elf, .hex
## How to use
```
cd image_parser/
mkdir build
cd ./build
cmake ..
make
./image_parser --help
```
## Parameter
|param1  |param2|feature                     |
|--------|------|----------------------------|
|--help  |none  |help info                   |
|--test  |route |read 96 Byte and print      |
|--header|route |print elf header information|
## Reference
1. [ELF offical handbook](https://www.cs.yale.edu/homes/aspnes/pinewiki/attachments/ELF(20)format/ELF_format.pdf)
