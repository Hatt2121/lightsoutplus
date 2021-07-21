struct utf8char {
    char hex[4];
};

typedef struct utf8char utf8char;

void printchar(utf8char a)
{
    for(short i = 0; i < 4; i++)
    {
        printf("%c%c",a.hex[i]);
    }
}