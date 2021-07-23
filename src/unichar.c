#include "unichar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printutf8char(utf8char a)
{
    for(short i = 0; i < 4; i++)
    {
        printf("%c",a.hex[i]);
    }
}

unsigned char * utf8toString(utf8char a)
{
    unsigned char * ret = a.hex;
    return ret;
}

//This guys use is somewhat unknown, 
//All I really want is to 
unsigned char * append(utf8char a, utf8char b)
{
    int new_size = strlen(a.hex)+strlen(b.hex);
    char * ret = (char *) calloc(new_size,sizeof(char));

    for(int i = 0; i < strlen(a.hex); i++)
    {
        * ret = a.hex[i];
        ret++;
    }

    for(int i = 0; i < strlen(b.hex); i++)
    {
        * ret = b.hex[i];
        ret++;
    }
    return (unsigned char *) ret;
}

unsigned char * appendToString(unsigned char * string, utf8char b)
{
    int new_size = strlen(string)+strlen(b.hex);
    unsigned char * ret = (unsigned char *) calloc(new_size,sizeof(unsigned char));

    for(int i = 0; i < strlen(string); i ++)
    {

    }

    for(int i = 0; i < strlen(b.hex); i++)
    {
        * ret = b.hex[i];
        ret++;
    }
    return (unsigned char *) ret;
}