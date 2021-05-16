#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/parserpetest.h"

void error(char *str) {
    fprintf(stderr, "Error: %s\n", str);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc != 2)
        error("necessary param missing.");

    PEFILE pe;

    pe.filepath = argv[1];

    parserpetest_init(&pe);

    if(parserpetest_ispe(&pe))
        printf("File is a PE.\n");
    else 
        error("file is not a PE.\n");

    printf("Path: %s\n", pe.filepath);
    printf("Magic number: %x\n", pe.hdr_dos->e_magic);
    printf("Bytes on last page of file: %d\n", pe.hdr_dos->e_cblp);
    printf("Pages in file: %x\n", pe.hdr_dos->e_cp);
    printf("Relocations: %x\n", pe.hdr_dos->e_crlc);
    printf("Overlay number: %x\n", pe.hdr_dos->e_ovno);
    printf("File address of relocation table: %x\n", pe.hdr_dos->e_lfarlc);
    printf("COFF header offset: %x\n", pe.hdr_dos->e_lfanew);
    
    parserpetest_deinit(&pe);

    return 0; 
}
