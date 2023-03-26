#include <stdio.h>
#include <stdlib.h>

// binary tree
typedef struct binary_tree
{
    int value;
    short symbol;
    struct binary_tree *left;
    struct binary_tree *right;
} *bt;

// print binary tree
void print_tree(bt root);

// create empty binary tree
bt b_create(int value, short symbol);

//to fix
//bt push(bt root, int value, char symbol); 

// merge two binary trees into new one
bt merge(bt first, bt second);

// H-Tree search
void H_tree_search(char *anc, bt Tree, char *ans[]);
