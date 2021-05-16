#include "parserpetest.h" 

bool parserpetest_ispe(PEFILE *pe) {
    return (pe->hdr_dos->e_magic == 0x5a4d); //'MZ'
}

bool parserpetest_init(PEFILE *pe) {
    FILE *file = fopen(pe->filepath, "rb");
    
    if(!file) 
        return false;
    
    pe->hdr_dos = malloc(sizeof(IMAGE_DOS_HEADER));
    if(!pe->hdr_dos)
        return false;

    fread(pe->hdr_dos, sizeof(IMAGE_DOS_HEADER), 1, file);
    
    fclose(file);
    
    return true;
}

void parserpetest_deinit(PEFILE *pe) {
    if(pe->hdr_dos) 
        free(pe->hdr_dos);
}
