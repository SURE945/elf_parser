#ifndef __ELF_PARSER_ELF_H_HEADER__
#define __ELF_PARSER_ELF_H_HEADER__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "type.h"

typedef struct {
    unsigned char e_ident[16];
    Elf64_Half e_type;
    Elf64_Half e_machine;
    Elf64_Word e_version;
    Elf64_Addr e_entry;
    Elf64_Off  e_phoff;
    Elf64_Off  e_shoff;
    Elf64_Word e_flags;
    Elf64_Half e_ehsize;
    Elf64_Half e_phentsize;
    Elf64_Half e_phnum;
    Elf64_Half e_shentsize;
    Elf64_Half e_shnum;
    Elf64_Half e_shstrndx;
} Elf32_Ehdr;

void parse_elf_header(std::fstream &fin);

#endif