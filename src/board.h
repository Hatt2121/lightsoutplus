#ifndef BOARD_H
#define BOARD_H

#ifndef UNICHAR_H
#include "unichar.h"
#endif

#define ROWS 8
#define COLUMNS 8

#define BOXON {0xe2,0x96,0xa0}
#define BOXOFF {0xe2,0x96,0xa1}

//Prints a row. That being if the row
//only has 8 elements.
void pretty_print(char);

//Prints the board
void print_board(char *);

//This is a char * only if the columns<=8
unsigned char * board_gen(short columns, short rows);

//generates random character for 
//rows that have 8 columns.
unsigned char randchar();

#endif