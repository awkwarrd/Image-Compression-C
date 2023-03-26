#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "convertation/convertation.h"
#include "huffman/huffman.h"

int main(int argc, char* argv[])
{
    //convertation("images/3.bmp");
    huffman("images/3.bmp", "o.txt");
    return 0;  
}   