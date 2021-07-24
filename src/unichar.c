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
//Something is up with this function. I think.
unsigned char * utf8toString(utf8char a)
{
    unsigned char * ret = a.hex;
    return ret;
}

//This guys use is somewhat unknown, 
//All I really want is to 
unsigned char * append(utf8char a, utf8char b)
{
    int new_size = strlen(a.hex)+strlen(b.hex)+1;
    unsigned char * ret = (unsigned char *) calloc(new_size,sizeof(unsigned char));

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
    
    ret++;
    *ret = 0x00;

    ret = ret - new_size ;
    return ret;
}

unsigned char * appendToString(unsigned char * string, utf8char b)
{
    int new_size = strlen(string)+strlen(b.hex)+1;
    unsigned char * ret = (unsigned char *) calloc(new_size,sizeof(unsigned char));

    for(int i = 0; i < strlen(string); i ++)
    {
        * ret = * string;
        ret++;
        string++;
    }

    for(int i = 0; i < strlen(b.hex); i++)
    {
        * ret = b.hex[i];
        ret++;
    }

    ret++;
    *ret = 0x00;

    ret = ret - new_size;
    return ret;
}

//For debug puposes only.
void printHexString(unsigned char * a)
{
    unsigned char value = * a;
    while(value != 0x00)
    {
        printf("%.2x",value);
        a++;
        value = *a;
    }
    //Just so I can see the null character at the end of a string.
    //print("%s",string) acts really weird for me, so I want to see
    //the hex values as they are just so I am not going to go crazy.
    a++;
    value = *a;
    printf("%.2x",value);

}