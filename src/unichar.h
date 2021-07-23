#ifndef UNICHAR_H
#define UNICHAR_H

typedef struct utf8char utf8char;

void printchar(utf8char);

char * tochars(utf8char);

#endif