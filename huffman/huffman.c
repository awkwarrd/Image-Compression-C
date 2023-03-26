#include "huffman.h"

void huffman(char in_f[], char out_f[])
{
    printf("1213\n");
    FILE *in = fopen(in_f, "rb");
    FILE *out = fopen(out_f, "w");
    short text[1000000];
    int d[1000];
    for (int i = 0; i < 1000; i++)
        d[i] = 0;

    short x;
    int n = 0;
    while ((x = fgetc(in)) != EOF)
    {
        d[(int)(x)]++;
        text[n++] = x;
        //printf("%d ", (int)(x));
    }
    printf("1213\n");
    queue q = create();
    for (int i = 0; i < 1000; i++) 
    {
        if (d[i] > 0)
        {
            bt temp = b_create(d[i], i);
            insert(&q, temp);
        }
    }
    while (q.size > 1)
    {
        printf("%d", q.size);
        bt f = kill(&q);
        bt s = kill(&q);
        bt temp = merge(f, s);
        insert(&q, temp);       
    }
    printf("\n1");
    printf("\n1");
    //print_queue(q);
    printf("\n\n");
    char *ans[300];
    for (int i = 0; i < 300; i++)
        ans[i] = malloc(sizeof(char) * 1000);

    /*for (int i = 0; i < 300; i++)
    {
        printf("%d\n", i);
        ans[i] = NULL;
        printf("%d\n", i);
    }*/
    printf("Hasd");
    

    bt H_tree = q.array[0];
    print_tree(H_tree);
    printf("\n%d\n", H_tree->value);
    return;
    H_tree_search("", H_tree, &ans);
    for (int i = 0; i < 300; i++)
        if (ans[i][0] != '1' && ans[i][0] != '0')ck
            printf("(%d - %s)\n", (i), ans[i]);
    printf("afasd");
    return;
    int separator = 0;
    short temp = 0;
    printf("%d", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; ans[text[i]][j] == '1' || ans[text[i]][j] == '0'; j++)
        {
            if (separator == 8)
            {
                printf("%c - %d\n", temp, temp);
                fputc((char)(temp), out);
                separator = 0;
                temp = 0;
            }
            if (ans[text[i]][j] == '1')
                temp = temp + (1 << (7 - separator));
            separator += 1;
            
           //printf("%c", ans[text[i]][j]);
        }
    }
    printf("\n\n");
}