#include "../include/test.h"

void elf_parser_test(std::fstream &fin) {
    int len = 100;
    char buff[len];
    if (fin.read(buff, len)) {
        int cnt_bytes = fin.gcount();
        for (int i = 0; i < 100; i+=4) {
            for (int j = 0; j < 4; j++) {
                unsigned char c = buff[i + j];
                std::cout << std::hex << std::setfill('0') 
                << std::setw(2) << (unsigned int)(c) << " ";
            }
            std::cout << std::endl;
        }
    }
}