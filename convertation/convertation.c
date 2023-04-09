#include <stdio.h>

#include "convertation.h"

void convertation(char* filename)
{
    FILE *in = fopen(filename, "rb");
    FILE *out = fopen("char_convertation.txt", "w");
    if (!in)
    {
        printf("Cannot open file. Try again\n");
        return;
    }
    short x;
    while ((x = fgetc(in)) != EOF)
    {
        printf("%d ", x);
        fputc((char)x, out);
    }
    fclose(in);
    fclose(out);
}