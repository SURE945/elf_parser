#include <iostream>
#include <fstream>
#include <string>
#include "include/test.h"

int main(int argc, char* argv[]) {
    std::fstream fin(argv[2], std::ios::in | std::ios::binary);
    if (!fin.is_open()) {
        std::cout << "route error" << std::endl;
        exit(1);
    }

    if (argv[1][1] == 'h') {
        std::cout << "-t\t" << "read 100 Byte and print" << std::endl;
    } else if (argv[1][1] == 't') {
        elf_parser_test(fin);
    } else {
        std::cout << "invalid argument" << std::endl;
    }

    fin.close();
    return 0;
}