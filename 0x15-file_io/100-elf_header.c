#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * display_elf_header - Display the information contained in the ELF header.
 * @elf_header: A pointer to the ELF header structure.
 */
void display_elf_header(Elf64_Ehdr *elf_header)
{
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header->e_ident[i]);
	printf("\nClass:                             %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid");
	printf("Data:                              %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Invalid");
	printf("Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("OS/ABI:                            %s\n", elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Invalid");
	printf("ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %s\n", elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" : "Invalid");
	printf("Entry point address:               0x%lx\n", elf_header->e_entry);
}

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		return 98;
	}

	struct stat file_stat;
	if (fstat(fd, &file_stat) == -1)
	{
		perror("fstat");
		close(fd);
		return 98;
	}

	void *file_data = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file_data == MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		return 98;
	}

	Elf64_Ehdr *elf_header = (Elf64_Ehdr *)file_data;
	if (elf_header->e_ident[EI_MAG0] != ELFMAG0 || elf_header->e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header->e_ident[EI_MAG2] != ELFMAG2 || elf_header->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		munmap(file_data, file_stat.st_size);
		close(fd);
		return 98;
	}

	display_elf_header(elf_header);

	munmap(file_data, file_stat.st_size);
	close(fd);
	return 0;
}

