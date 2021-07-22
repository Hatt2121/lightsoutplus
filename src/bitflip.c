#include <stdio.h>

int main()
{
    int a = 0x323464;
    char * b = (char) &a;
    printf("%x",*b);
}