#include <stdio.h>
#include <math.h>

/*
 * The purpose of this file is to figure out some of the lower level stuff in order to use it in the lightsout..c file. Ignore this file. I, for some reason, can't configure git to ignore it, so just look at the fun that I am having here.
*/

int n_ones(int n);
struct utf8char {
    char hex[4];
};

typedef struct utf8char utf8char;

int main()
{
    utf8char a = {0x00,0x00,0x00,0x61}; //wait, why can I do this, why isnt it a.hex?
    utf8char box = {0xe2,0x96,0xa1};
    utf8char box2 = {0xe2,0x96,0xa0};
    for(int i = 0; i < 4; i++)
    { 
        printf("%c",box.hex[i]);
    }
    printf("\n");
    for(int i = 0; i < 4; i++)
    { 
        printf("%c",box2.hex[i]);
    }
    printf("\n");
}
/*
int n_ones(int n)
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        j = j + pow(2,i);
    }
    return j;
}*/