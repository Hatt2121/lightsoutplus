#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

utf8char box_on = BOXON;
utf8char box_off = BOXOFF;

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
    //I have to rewrite this whole part because I can't always
    //just print out 8 rows. Boards are meant to be different sizes.
}

unsigned char * rand_board_gen(short columns, short rows)
{
    unsigned char * ret = (unsigned char *) calloc(ROWS,sizeof(char));
    srand(time(NULL));
    for(int x = 0; x < ROWS; x++)
    {
        ret[x] = randchar();
    }
    return ret;
}

unsigned char randchar()
{   
    return ((unsigned char) rand() % 255);
}

unsigned char * board_string(unsigned char * rows)
{
    
}