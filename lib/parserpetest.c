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

    if(fread(pe->hdr_dos, sizeof(IMAGE_DOS_HEADER), 1, file) != 1) {
        return false;
    }

    int coff = pe->hdr_dos->e_lfanew + 0x4;

    if(fseek(file, coff, SEEK_SET) == -1) 
        return false;
  
    pe->hdr_coff = malloc(sizeof(IMAGE_COFF_HEADER));
    if(!pe->hdr_coff)
        return false;

    if(fread(pe->hdr_coff, sizeof(IMAGE_COFF_HEADER), 1, file) != 1) {
        return false;
    }
    
    fclose(file);
    
    return true;
}

void parserpetest_deinit(PEFILE *pe) {
    if(pe->hdr_dos) 
        free(pe->hdr_dos);

    if(pe->hdr_coff)
        free(pe->hdr_coff);
}
