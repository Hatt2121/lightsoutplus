#include <stdio.h>
#include <stdlib.h>
#include "unichar.h"
#include "board.h"

utf8char box_on = BOXON;

utf8char box_off = BOXOFF;

int main()
{
    char flip_column = 4;
    char flip_row = 5;

    unsigned char * rows =(unsigned char*) calloc(ROWS ,sizeof(unsigned char)); //create a board of rows 
    for(char i = 0; i < ROWS; i++) {
        rows[i] = (char) 0;
    } //turn the whole board off.

    //I'll write a file reading portion later.
    rows[0] = 0xff;
    rows[1] = 0x81;
    rows[2] = 0x81;
    rows[3] = 0x81;
    rows[4] = 0x81;
    rows[5] = 0x81;
    rows[6] = 0x81;
    rows[7] = 0xff;
    //This is the starting grid.

    print_board(rows);
    
    char shift_number = 7 - flip_column;
    char flip_number = 7; //0b111
    if(shift_number == -1)
    {
        flip_number = flip_number >> 1;
    } else {
        flip_number = flip_number<<shift_number;
    }

    
    rows[flip_row-1] = rows[flip_row-1] ^ flip_number;
    rows[flip_row] = rows[flip_row] ^ flip_number;
    rows[flip_row+1] = rows[flip_row+1] ^ flip_number;

    printf("\n");

    print_board(rows);

   free(rows);
   return 1;
}

// Turns a row of binary into a string of on and off characters.
void pretty_print(char row)
{
    for(short i = 0; i < 8; i++)
    {
        if((row & (0b1 << i)) == (0b1<<i))
        {
            printutf8char(box_on);
        } else {
            printutf8char(box_off);  
        }
        printf(" ");
    }
    printf("\n");
}

void print_board(char * rows)
{
    for(short i = 0; i < 8; i++)
    {
        pretty_print(*rows);
        rows++;
    }
}