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

enum elf_machine {
    EM_NONE         = 0,
    EM_M32          = 1,
    EM_SPARC        = 2,
    EM_386          = 3,
    EM_68K          = 4,
    EM_88K          = 5,
    EM_486          = 6,
    EM_860          = 7,
    EM_MIPS         = 8,
    EM_MIPS_RS3     = 10,
    EM_PARISC       = 15,
    EM_SPARC32PLUS  = 18,
    EM_PPC          = 20,
    EM_PPC64        = 21,
    EM_SPU          = 23,
    EM_ARM          = 40,
    EM_SH           = 42,
    EM_SPARCV9      = 43,
    EM_H8_300       = 46,
    EM_IA_64        = 50,
    EM_X86_64       = 62,
    EM_S390         = 22,
    EM_CRIS         = 76,
    EM_M32R         = 88,
    EM_MN10300      = 89,
    EM_OPENRISC     = 92,
    EM_ARCOMPACT    = 93,
    EM_XTENSA       = 94,
    EM_BLACKFIN     = 106,
    EM_UNICORE      = 110,
    EM_ALTERA_NIOS2 = 113,
    EM_TI_C6000     = 140,
    EM_HEXAGON      = 164,
    EM_NDS32        = 167,
    EM_AARCH64      = 183,
    EM_TILEPRO      = 188,
    EM_MICROBLAZE   = 189,
    EM_TILEGX       = 191,
    EM_ARCV2        = 195,
    EM_RISCV        = 243,
    EM_BPF          = 247,
    EM_CSKY         = 252,
    EM_LOONGARCH    = 258,
    EM_FRV          = 0x5441
};

void parse_elf_header(std::fstream &fin);

#endif