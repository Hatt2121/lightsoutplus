#include "unichar.h"

struct utf8char {
    unsigned char hex[4];
};

void printchar(utf8char a)
{
    for(short i = 0; i < 4; i++)
    {
        printf("%c",a.hex[i]);
    }
}

char * tochars(utf8char a)
{
    unsigned char * ret = a.hex;
    return ret;
}