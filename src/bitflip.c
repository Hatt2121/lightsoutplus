#include <stdio.h>
#include "unichar.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    utf8char g = {0xf0,0x9f,0x98,0x80}; //GRINNING FACE emoji
    utf8char a = {0xe2,0xac,0x86}; //UPWARDS BLACK ARROW
    utf8char d = {0xd1,0xa8}; //Some Cyrillic Character (I don't know it takes up two bytes in utf8 though)
    srand(time(NULL));
    printf("%x\n",(unsigned char) rand() % 255);
}