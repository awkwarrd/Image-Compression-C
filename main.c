#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "convertation/convertation.h"
#include "huffman/huffman.h"

int main(int argc, char* argv[])
{
    
    if (!strcmp(argv[1],"-h"))
    {
        printf("Huffman's coding\n\n");
        printf("Arguments of a.out :\n");
        printf("./a.out [name of file.bmp] (-t)\n");
        printf("\n");
        printf("This program compress image with the help of Huffman's algorithm\n");
        printf("Result of program is file \"Huffman_Compression.txt\", which conteins compressed file\n");
        printf("Add \"-t\" to print Huffman's tree in console\n");
        return 0;
    }
    bt H_tree = malloc(sizeof(bt));
    H_tree = huffman(argv[1], "Huffman_Compression.txt");
    printf("Compression completed\n");
    
    
    // Compression ratio
    FILE *f1 = fopen(argv[1], "rb");
    FILE *f2 = fopen("Huffman_Compression.txt", "rb");
    

    // Seek to the end of the file
    fseek(f1, 0L, SEEK_END);
    fseek(f2, 0L, SEEK_END);

    // Get the current position, which is the size of the file
    long size1 = ftell(f1);
    long size2 = ftell(f2);

    printf("Compression ratio : %f\n", (float)(size1) / (float)(size2));
    if (argc > 2 && !strcmp(argv[2],"-t"))
    {
        printf("Huffman's tree: \n");
        print_tree(H_tree, 0);
    }
    
    fclose(f1);
    fclose(f2);
    return 0;  
}   