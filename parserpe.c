#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/parserpetest.h"

void error(char *str) {
    fprintf(stderr, "Error: %s\n", str);
    exit(1);
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
    
    if(!parserpetest_ispe(buffer)) 
        error("file doesn't look like a PE.");

    return 0; 
}
