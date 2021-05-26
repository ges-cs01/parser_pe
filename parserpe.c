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
    printf("\n---DOS Header---\n");
    printf("\tMagic number: 0x%x\n", pe.hdr_dos->e_magic);
    printf("\tBytes on last page of file: %d\n", pe.hdr_dos->e_cblp);
    printf("\tPages in file: %x\n", pe.hdr_dos->e_cp);
    printf("\tRelocations: %x\n", pe.hdr_dos->e_crlc);
    printf("\tOverlay number: %x\n", pe.hdr_dos->e_ovno);
    printf("\tFile address of relocation table: 0x%x\n", pe.hdr_dos->e_lfarlc);
    printf("\tCOFF header offset: 0x%x\n", pe.hdr_dos->e_lfanew);
    printf("\n---COFF Header---\n");
    printf("\tMachine:: 0x%x\n", pe.hdr_coff->Machine);
    printf("\tTime date stamp: %d\n", pe.hdr_coff->TimeDateStamp);
    printf("\tNumber of sections: %x\n", pe.hdr_coff->NumberOfSections);
    printf("\tPointer to symbols: %x\n", pe.hdr_coff->PointerToSymbolTable);
    printf("\tNumber of symbols: %x\n", pe.hdr_coff->NumberOfSymbols);
    printf("\tSize of optional header: 0x%x\n", pe.hdr_coff->SizeOfOptionalHeader);
    printf("\tCharacteristics: 0x%x\n", pe.hdr_coff->Characteristics);

    parserpetest_deinit(&pe);

    return 0; 
}
