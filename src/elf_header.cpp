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
    std::string space = "\t\t\t\t\t";
    std::cout << "Class:" << space;
    switch (header.e_ident[4])
    {
    case 0:
        std::cout << "Invalid class" << std::endl;
        break;
    case 1:
        std::cout << "32-bit objects" << std::endl;
        break;
    case 2:
        std::cout << "64-bit objects" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Data:" << space;
    switch (header.e_ident[5])
    {
    case 0:
        std::cout << "Invalid data encoding" << std::endl;
        break;
    case 1:
        std::cout << "little endian" << std::endl;
        break;
    case 2:
        std::cout << "big endian" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Version:" << "\t\t\t\t" << (int)header.e_ident[6] << std::endl;
    std::cout << "Type:" << space;
    switch (header.e_type)
    {
    case 0:
        std::cout << "No file type" << std::endl;
        break;
    case 1:
        std::cout << "Relocatable file" << std::endl;
        break;
    case 2:
        std::cout << "Executable file" << std::endl;
        break;
    case 3:
        std::cout << "Shared object file" << std::endl;
        break;
    case 4:
        std::cout << "Core file" << std::endl;
        break;
    case 0xff00:
        std::cout << "Processor-specific" << std::endl;
        break;
    case 0xffff:
        std::cout << "Processor-specific" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Machine:" << "\t\t\t\t";
    switch (header.e_machine)
    {
    case 0:
        std::cout << "No machine" << std::endl;
        break;
    case 1:
        std::cout << "AT&T WE 32100" << std::endl;
        break;
    case 2:
        std::cout << "SPARC" << std::endl;
        break;
    case 3:
        std::cout << "Intel 80386" << std::endl;
        break;
    case 4:
        std::cout << "Motorola 68000" << std::endl;
        break;
    case 5:
        std::cout << "Motorola 88000" << std::endl;
        break;
    case 7:
        std::cout << "Intel 80860" << std::endl;
        break;
    case 8:
        std::cout << "MIPS RS3000" << std::endl;
        break;
    default:
        std::cout << "Other machine" << std::endl;
        break;
    }
    std::cout << "Entry point address:" << "\t\t\t" << std::hex << "0x" << header.e_entry << std::endl;
    std::cout << "Start of Program headers: " << "\t\t" << std::dec << header.e_phoff << std::endl;
    std::cout << "Start of Section headers: " << "\t\t" << std::dec << header.e_shoff << std::endl;
    std::cout << "Flags: " << space << std::hex << "0x" << header.e_flags << std::endl;
    std::cout << "Size of this header: " << "\t\t\t" << std::dec << header.e_ehsize << std::endl;
    std::cout << "Size of Program header: " << "\t\t" << std::dec << header.e_phentsize << std::endl;
    std::cout << "Number of Program header: " << "\t\t" << std::dec << header.e_phnum << std::endl;
    std::cout << "Size of Section header: " << "\t\t" << std::dec << header.e_shentsize << std::endl;
    std::cout << "Number of Section header: " << "\t\t" << std::dec << header.e_shnum << std::endl;
    std::cout << "Section header string table index: " << "\t" << std::dec << header.e_shstrndx << std::endl;
}