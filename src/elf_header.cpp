#include "elf_header.h"

void parse_elf_header(std::fstream &fin) {
    Elf32_Ehdr header;
    if (fin.read((char*)(&header), sizeof(header))) {
        std::cout << "ELF Header: " << std::endl;
        std::cout << "Magic: ";
        for (int i = 0; i < 16; i++) {
            std::cout << std::hex << std::setfill('0') << std::setw(2) 
                        << (unsigned int)header.e_ident[i] << " ";
        }
        std::cout << std::endl;
    }
    std::string space = "\t\t\t";
    std::cout << "Class:" << space;
    switch (header.e_ident[4])
    {
    case 0:
        std::cout << "ELFCLASSNONE" << std::endl;
        break;
    case 1:
        std::cout << "ELFCLASS32" << std::endl;
        break;
    case 2:
        std::cout << "ELFCLASS64" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Data:" << space;
    switch (header.e_ident[5])
    {
    case 0:
        std::cout << "ELFDATANONE" << std::endl;
        break;
    case 1:
        std::cout << "ELFDATA2LSB" << std::endl;
        break;
    case 2:
        std::cout << "ELFDATA2MSB" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Version:" << "\t\t" << (int)header.e_ident[6] << std::endl;
    std::cout << "Type:" << space;
    switch (header.e_type)
    {
    case 0:
        std::cout << "ET_NONE" << std::endl;
        break;
    case 1:
        std::cout << "ET_REL" << std::endl;
        break;
    case 2:
        std::cout << "ET_EXEC" << std::endl;
        break;
    case 3:
        std::cout << "ET_DYN" << std::endl;
        break;
    case 4:
        std::cout << "ET_CORE" << std::endl;
        break;
    case 0xff00:
        std::cout << "ET_LOPROC" << std::endl;
        break;
    case 0xffff:
        std::cout << "ET_HIPROC" << std::endl;
        break;
    default:
        break;
    }
}