#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "test.h"
#include "help.h"
#include "elf_header.h"

bool error_report(int argc) {
    bool res = 0;
    if (argc < 3) {
        std::cout << "no valid route, please input --help to get help" << std::endl;
        res = 1;
    }
    return res;
}

bool file_open(std::fstream &fin, char* argv, bool bin) {
    bool res = 0;
    if (bin) {
        fin.open(argv, std::ios::in | std::ios::binary);
    } else {
        fin.open(argv, std::ios::in);
    }
    if (!fin.is_open()) {
        std::cout << "route error" << std::endl;
        res = 1;
    }
    return res;
}

int main(int argc, char* argv[]) {
    std::fstream fin;

    if (!strcmp(argv[1], "--help")) {
        print_help_information();
    } else if (!strcmp(argv[1], "--test")) {
        if (error_report(argc)) {exit(1);}
        if (file_open(fin, argv[2], 1)) {exit(1);}
        elf_parser_test(fin);
    } else if (!strcmp(argv[1], "--header")) {
        if (file_open(fin, argv[2], 1)) {exit(1);}
        if (error_report(argc)) {exit(1);}
        parse_elf_header(fin);
    } else {
        std::cout << "invalid argument" << std::endl;
    }

    fin.close();
    return 0;
}