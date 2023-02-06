#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define EI_NIDENT 16
#define ELFCLASSNONE 0
#define ELFCLASS32 1
#define ELFCLASS64 2

#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

#define EV_NONE 0
#define EV_CURRENT 1

typedef struct {
  unsigned char e_ident[EI_NIDENT];
  uint16_t e_type;
  uint16_t e_machine;
  uint32_t e_version;
  uint64_t e_entry;
  uint64_t e_phoff;
  uint64_t e_shoff;
  uint32_t e_flags;
  uint16_t e_ehsize;
  uint16_t e_phentsize;
  uint16_t e_phnum;
  uint16_t e_shentsize;
  uint16_t e_shnum;
  uint16_t e_shstrndx;
} Elf64_Ehdr;

const char *class_strings[] = {
  "none",
  "ELF32",
  "ELF64"
};

const char *data_strings[] = {
  "none",
  "2's complement, little endian",
  "2's complement, big endian"
};

const char *version_strings[] = {
  "none",
  "1 (current)"
};

const char *type_strings[] = {
  "NONE (none)",
  "REL (Relocatable file)",
  "EXEC (Executable file)",
  "DYN (Shared object file)",
  "CORE (Core file)"
};

void display_elf_header(Elf64_Ehdr *ehdr) {
  int class = ehdr->e_ident[4];
  int data = ehdr->e_ident[5];
  int version = ehdr->e_ident[6];

  printf("ELF Header:\n");
  printf("  Magic:   %02x %02x %02x %02x\n",
         ehdr->e_ident[0],
         ehdr->e_ident[1],
         ehdr->e_ident[2],
         ehdr->e_ident[3]);
  printf("  Class:                             %s\n", class_strings[class]);
  printf("  Data:                              %s\n", data_strings[data]);
  printf("  Version:                           %s\n", version_strings[version]);
  printf("  OS/ABI:                            UNIX - System V\n");
  printf("  ABI Version:                       0\n");
  printf("  Type:                              %s\n", type_strings[ehdr->e_type]);
  printf("  Entry point address:               %llx\n", ehdr);
  printf("  Entry point address:               %llx\n", ehdr->e_entry);
  printf("  Start of program headers:          %llx (bytes into file)\n", ehdr->e_phoff);
  printf("  Start of section headers:          %llx (bytes into file)\n", ehdr->e_shoff);
  printf("  Flags:                             0x%x\n", ehdr->e_flags);
  printf("  Size of this header:               %d (bytes)\n", ehdr->e_ehsize);
  printf("  Size of program headers:           %d (bytes)\n", ehdr->e_phentsize);
  printf("  Number of program headers:         %d\n", ehdr->e_phnum);
  printf("  Size of section headers:           %d (bytes)\n", ehdr->e_shentsize);
  printf("  Number of section headers:         %d\n", ehdr->e_shnum);
  printf("  Section header string table index: %d\n", ehdr->e_shstrndx);
}

int main(int argc, char *argv[]) {
  int fd;
  Elf64_Ehdr ehdr;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
    return 1;
  }

  if ((fd = open(argv[1], O_RDONLY)) < 0) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return 2;
  }

  if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return 3;
  }

  if (ehdr.e_ident[0] != 0x7f ||
      ehdr.e_ident[1] != 'E' ||
      ehdr.e_ident[2] != 'L' ||
      ehdr.e_ident[3] != 'F') {
    fprintf(stderr, "Error: Not an ELF file\n");
    return 98;
  }

  display_elf_header(&ehdr);

  return 0;
}

