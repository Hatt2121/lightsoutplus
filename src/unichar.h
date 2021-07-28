#ifndef UNICHAR_H
#define UNICHAR_H

struct utf8char {
    unsigned char hex[4];
};

typedef struct utf8char utf8char;

void printutf8char(utf8char);

short utf8charlen(utf8char); //This number should be 4 or less.

unsigned char * utf8toString(utf8char);

unsigned char * append(utf8char,utf8char);

unsigned char * appendToString(unsigned char *, utf8char);

//Adds utf8character to a string that is being pointed at.
void modify_append_utf8(unsigned char **, utf8char);

void printHexString(unsigned char * a);

#endif