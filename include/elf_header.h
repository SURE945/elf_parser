#ifndef __ELF_PARSER_ELF_H_HEADER__
#define __ELF_PARSER_ELF_H_HEADER__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "type.h"

typedef struct {
    unsigned char e_ident[16];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off  e_phoff;
    Elf32_Off  e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;

void parse_elf_header(std::fstream &fin);

#endif