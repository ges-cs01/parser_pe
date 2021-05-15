#include "parserpetest.h" 

bool parserpetest_ispe(const unsigned char *buffer) {
    return (buffer[0] == 'M' && buffer[1] == 'Z');
}
