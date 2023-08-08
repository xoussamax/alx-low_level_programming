#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>

void display_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void display_elf_header(const Elf64_Ehdr *elf_header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    switch (elf_header->e_ident[EI_CLASS]) {
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown>\n");
    }
    printf("  Data:                              ");
    switch (elf_header->e_ident[EI_DATA]) {
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n");
    }
    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        default: printf("<unknown: %d>\n", elf_header->e_ident[EI_OSABI]);
    }
    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (elf_header->e_type) {
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        default: printf("<unknown>\n");
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        display_error("Error opening file");
    }

    Elf64_Ehdr elf_header;
    ssize_t read_size = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (read_size != sizeof(Elf64_Ehdr)) {
        display_error("Error reading ELF header");
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        display_error("Not an ELF file");
    }

    display_elf_header(&elf_header);

    close(fd);

    return 0;
}

