#include <stdio.h>
#include "unichar.h"
#include <string.h>

int main()
{
    utf8char g = {0xf0,0x9f,0x98,0x80}; //GRINNING FACE emoji
    utf8char a = {0xe2,0xac,0x86}; //UPWARDS BLACK ARROW

    unsigned char * c = append(a,g);

    printf("%s",c);

}