#include <stdio.h>
#include "unichar.h"
#include <string.h>

int main()
{
    utf8char g = {0xf0,0x9f,0x98,0x80}; //GRINNING FACE emoji
    utf8char a = {0xe2,0xac,0x86}; //UPWARDS BLACK ARROW

    unsigned char * b = utf8toString(g);
    unsigned char * c = appendToString(b,a);

    printf("%.8x\n",b);
    printf("%.8x\n",c);
    printf("\n");
    printf("%s",b);
    printf("%s",c);
}