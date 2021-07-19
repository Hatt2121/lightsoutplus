#include <stdio.h>
#include <math.h>

int n_ones(int n);

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