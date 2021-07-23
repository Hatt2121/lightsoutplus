#ifndef UNICHAR_H
#define UNICHAR_H

struct utf8char {
    unsigned char hex[4];
};

typedef struct utf8char utf8char;

void printutf8char(utf8char);

unsigned char * utf8toString(utf8char);

unsigned char * append(utf8char,utf8char);

unsigned char * appendToString(unsigned char *, utf8char);

#endif