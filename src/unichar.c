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

short utf8charlen(utf8char a)
{
    //This is going to use bit manipulation to calculate the length.
    //Based on the utf8 standard. Luckily its all in the first byte :).
    short ret = -1;
    unsigned char first_byte = a.hex[0];

    if(first_byte<=((unsigned char) 0x7f))
    {
        ret = 1;
    } else if(first_byte>= ((unsigned char) 0xc0) & first_byte<= (unsigned char) 0xdf) {
        ret = 2;
    } else if(first_byte<= ((unsigned char)0xef)) {
        ret = 3;
    } else if(first_byte<=((unsigned char)0xf7)) {
        ret = 4;
    }
    
    return ret;
}

//This guys use is somewhat unknown, 
//All I really want is to 
unsigned char * append(utf8char a, utf8char b)
{
    //We know that these types are both 4 characters wide (or less)
    //So the new size is going to be basically 9 characters.
    //Im trying to figure out how I might be able to shorten that if
    //The utf8chars have a zero. Basically strlen() is a problematic function.
    short new_size = utf8charlen(a)+utf8charlen(b) +1;
    unsigned char * ret = (unsigned char *) calloc(new_size,sizeof(unsigned char));

    for(short i = 0; i < utf8charlen(a); i++)
    {
        * ret = a.hex[i];
        ret++;
    }

    for(short i = 0; i < utf8charlen(b); i++)
    {
        * ret = b.hex[i];
        ret++;
    }
    
    ret++;
    *ret = 0x00;

    ret = ret - new_size;
    return ret;
}

unsigned char * appendToString(unsigned char * string, utf8char b)
{
    int new_size = strlen(string)+ utf8charlen(b)+1;
    unsigned char * ret = (unsigned char *) calloc(new_size,sizeof(unsigned char));

    for(short i = 0; i < strlen(string); i ++)
    {
        * ret =  string[i];
        ret++;
    }

    for(short i = 0; i < utf8charlen(b); i++)
    {
        * ret = b.hex[i];
        ret++;
    }

    ret++;
    *ret = 0x00;

    ret = ret - new_size;
    return ret;
}

//Instead of returning the value, it appends  a to'string'
//and modifies it instead of returning it.
//Sadly you need to point to the string itself, but, its fine.
void modifyToString(unsigned char ** string_pointer, utf8char a) {
    * string_pointer = appendToString(*string_pointer, a);
}

//For debug puposes only.
//Prints out the hex values of a string, including the 00.
//Stops when it sees 0x00.
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