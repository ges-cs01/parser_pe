#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void error(char *str) {
    fprintf(stderr, "Error: %s\n", str);
    exit(1);
}

bool is_pe(const unsigned char *buffer) {
    return(buffer[0] != 'M' && buffer[1] != 'Z');
}

int main(int argc, char *argv[]) {
    FILE *file;
    unsigned char buffer[32];

    if(argc != 2)
        error("necessary param missing.");

    file = fopen(argv[1], "rb");
    
    if(file == NULL) 
        error("file not found or without read permission.");

    if(fread(buffer, 32, 1, file) != 1) 
        error("could not read bytes");

    fclose(file);
    
    if(!is_pe(buffer)) 
        error("file doesn't look like a PE.");

    return 0; 
}
