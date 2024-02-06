#include "help.h"

void print_help_information() {
    std::cout << "--help\t\t" << "help information" << std::endl;
    std::cout << "--test route\t" << "read 96 Byte and print" << std::endl;
    std::cout << "--header route\t" << "print elf header information" << std::endl;
}