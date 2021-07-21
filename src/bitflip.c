#include <stdio.h>
#include <math.h>

/*
 * The purpose of this file is to figure out some of the lower level stuff in order to use it in the lightsout..c file. Ignore this file. I, for some reason, can't configure git to ignore it, so just look at the fun that I am having here.
*/

int n_ones(int n);

struct unichar {
    char hex[3];
};

typedef struct unichar unichar;

int main()
{
   unsigned char a = 255;
   char b = (signed char) a;

   printf("%d\n",b);
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