#include <stdio.h>

#include "convertation.h"


void convertation(char* filename)
{
    FILE *in = fopen(filename, "rb");
    FILE *out = fopen("convertation.txt", "w");

    if (!in)
    {
        printf("Cannot open file. Try again\n");
        return;
    }
    short x;
    short st = 1;
    short result = 0;
    while ((x = fgetc(in)) != EOF)
    {
        for (int i = 0; i <= 7; i++)
        {
            if (x & (1 << (7 - i)))
            {
                fputc('1', out);
                result += st;
            }
            else fputc('0', out);
            st *= 2;
        }
        st = 1;
        printf("%d ", result);
        //fputc((char)result, out);
        result = 0;
        
        //fputc((char)x,out);
    }
    fclose(in);
    fclose(out);
    return ;   
}