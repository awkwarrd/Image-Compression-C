#include "huffman.h"

bt huffman(char in_f[], char out_f[])
{
    FILE *in = fopen(in_f, "rb"); 
    FILE *out = fopen(out_f, "w");

    if (!in)
    {
        printf("Cannot open file. Try again\n");
        printf("Use ./a.out -h for help\n");
        return NULL;
    }

    short text[1000000];
    int counter[1000];
    
    for (int i = 0; i < 1000; i++)
        counter[i] = 0;

    short x;
    int n = 0;
    while ((x = fgetc(in)) != EOF)
    {
        counter[(int)(x)]++;
        text[n++] = x;
    }

    queue q = create();
    for (int i = 0; i < 1000; i++) 
    {
    
        if (counter[i] > 0)
        {
            bt temp = b_create(counter[i], i);
            insert(&q, temp);
        }
    }

    while (q.size > 1)
    {
        bt f = kill(&q);
        bt s = kill(&q);
        bt temp = merge(f, s);
        insert(&q, temp);       
    }

    char *ans[300];
    for (int i = 0; i < 300; i++)
        ans[i] = malloc(sizeof(char) * 1000);

   
    bt H_tree = q.array[0];
    H_tree_search("", H_tree, &ans);
   
   
    int separator = 0;
    short temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; ans[text[i]][j] == '1' || ans[text[i]][j] == '0'; j++)
        {
            if (separator == 8)
            {
                fputc((char)(temp), out);
                separator = 0;
                temp = 0;
            }
            if (ans[text[i]][j] == '1')
                temp = temp + (1 << (7 - separator));
            separator += 1;
        }
    }
    if (separator > 0)
        fputc((char)(temp), out);


    fclose(in);
    fclose(out);
    return H_tree;
}