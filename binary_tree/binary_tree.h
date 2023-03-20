#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree
{
    int value;
    char symbol;
    struct binary_tree *left;
    struct binary_tree *right;
} *bt;

void print_tree(bt root);
bt create(int value, char symbol);

//to fix
//bt push(bt root, int value, char symbol); 

bt merge(bt first, bt second);