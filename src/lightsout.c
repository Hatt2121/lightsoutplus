#include <stdio.h>
#include <stdlib.h>
#include "unichar.c"

#ifndef ROWS
#define ROWS 8
#endif

#ifndef COLUMNS
#define COLUMNS 8
#endif

//Defines the character for on in utf-8 hex.
//I'm having a hard time trying to make this mutable in the pretty_print function.
//For now, I will use a pointer to point at the 3 bytes.

utf8char box_on = {0xe2,0x96,0xa0};
utf8char box_off = {0xe2,0x96,0xa1};

/**
* Each row is a byte, and each binary digit represents whether it is on or off
* On - 1
* Off - 0
* For now, because I can't really do otherwise, the grid is going to be an 8 x 8
* So I am deciding that the max size is going to be an
*/

char * pretty_print(char);
void print_board(char *);

int main()
{
    char flip_column = 4;
    char flip_row = 5;

    unsigned char * rows =(unsigned char*) calloc(ROWS ,sizeof(unsigned char)); //create a board of rows 
    for(char i = 0; i < ROWS; i++) {
        rows[i] = (char) 0;
    } //turn the whole board off.

    //I'll write a file reading portion later.
    rows[0] = 0b11111111;
    rows[1] = 0b10000001;
    rows[2] = 0b10000001;
    rows[3] = 0b10000001;
    rows[4] = 0b10000001;
    rows[5] = 0b10000001;
    rows[6] = 0b10000001;
    rows[7] = 0b11111111;
    //This is the starting grid.

    print_board(rows);
    //When flipping a 3 x 3 portion of the grid, what you are really doing is 
    //flipping the bits between 1 behind the center 1 in front of the center, in both columns and rows.
    //Telling the computer to go between rows is easy, but doing the actual bitwise operation is pretty hard.
    //The bits have to be located a certain distance away from the digit that you want.
    //This part of the documentation I am going to write by hand.

    //For now, we are only going to specify flipping something that is 3x3.
    //So we really don't need to use the n_ones function just yet,
    //That being said, we would instead use the number 7 to represent 111 (which is the flip_number.)
    //Allowing us to flip 3 bits in a row using a bitwise xor operator.

    //There are positions in a row numbering from 0 to 7 (because it's a byte), so we take that, subtract that with 
    //the position that you want, and further subtract that by 1, which is the extra part between the middle of the 
    //flipping area, and the edge of the flipping area. If the number is -1 it means we need to bitshift it right.
    
    //I'm using char because I want to restrict myself with using only byte operations.

    /*
    * shift_number is the number of times that the number has to shift left in order for the center of the flipped bits 
    * to reach the flip_column.
    * The number 7 on the expression defining shift_number is the index of the last column of the board. Therefore,
    * we can replace it using (ROWS-1)
    */
    char shift_number = 7 - flip_column-3;
    char flip_number = 7; //0b111
    if(shift_number == -1)
    {
        flip_number = flip_number >> 1;
    } else {
        flip_number = flip_number<<shift_number;
    }

    //Now we have the number that we can change the rows by. Now just flips the rows from 1 minus and plus the row number,
    //as well as including the row number
    //This is specific only for a 3 by 3 case.
    rows[flip_row-1] = rows[flip_row-1] ^ flip_number;
    rows[flip_row] = rows[flip_row] ^ flip_number;
    rows[flip_row+1] = rows[flip_row+1] ^ flip_number;

    printf("\n");

    print_board(rows);

    /*
    *   Now we need to figure out how print out the numbers into something readable.
    * It should be pretty hard to play a visual game using only hexadecimal numbers.
    * Even printing them out with a binary representation would be better than nothing.
    *
    * 
    */

   free(rows);
   return 1;
}

/*
// This is used to make the numbers for the flipping area.
char n_ones(char n)
{
    //Returns a number that contains n ones. e.g. {111}_bin
    char j = 0;
    if(n < 9)
    {
        for(char i = 0; i < n; i++)
        {
            j = j + ((char) pow(2,i));
        }
    }
    return j;
}
*/

/* Limited to 32 rows and 32 columns
 * Will be used later when I decide to make this more open.
 *
 */
/*
unsigned int * board_generator(unsigned char rows, unsigned char columns)
{
    if(rows>32 || rows <32)
    {
        printf("Board that you demand is too big. Choose a number below 32 rows or 32 columns.\n");
    } else {
        unsigned int * board = calloc(ROWS, sizeof(unsigned int));
        for(unsigned short i = 0; i < rows; i++)
        {
            board[i] = (unsigned int) 0;
        }
    }
}
*/

// Turns a row of binary into a string of on and off characters.
char * pretty_print(char row)
{
    for(char i = 0; i < 8; i++)
    {
        if((row & (0b1 << i)) == (0b1<<i))
        {
            printchar(box_on);
        } else {
            printchar(box_off);
        }
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