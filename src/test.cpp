#include "../include/test.h"

void elf_parser_test(std::fstream &fin) {
    int len = 0x60;
    char buff[len];
    if (fin.read(buff, len)) {
        int cnt_bytes = fin.gcount();
        for (int i = 0; i < len; i+=0x10) {
            std::cout << std::hex << std::setfill('0') << std::setw(4) << i << " ";
            for (int j = 0; j < 0x10; j++) {
                unsigned char c = buff[i + j];
                std::cout << std::hex << std::setfill('0') 
                << std::setw(2) << (unsigned int)(c);
                if (((j + 1) % 4 == 0)) {
                    std::cout << " ";
                }
            }
            for (int j = 0; j < 0x10; j++) {
                char c = buff[i + j];
                if ((c < 127) && (c > 20)) {
                    std::cout << c;
                } else {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
    }
}