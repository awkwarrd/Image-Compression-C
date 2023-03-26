#include <string.h>
#include "binary_tree.h"

void print_tree(bt root)
{
    if (root != NULL)
    {
        print_tree(root->left);
        printf("(%d - %c) ", root->value, root->symbol);
        print_tree(root->right);
    }
}

bt b_create(int value, short symbol)
{
    bt temp = malloc(sizeof(bt));
    temp->value = value;
    temp->symbol = symbol;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bt merge(bt first, bt second)
{
    bt temp = b_create(first->value + second->value, (short)'.');
    if (first->value <= second->value)
    {
        temp->left = first;
        temp->right = second;
    }   
    else
    {
        temp->right = first;
        temp->left = second;
    }
    return temp;
}

void H_tree_search(char anc[1000], bt Tree, char *ans[300])
{
    if (Tree->symbol != '.')
    {

        ans[(int)Tree->symbol] = anc;
        printf("1");
        //printf("(%s - %d) === %d\n", anc, Tree->symbol, Tree->value);
        return;
    }
    char r = '1';
    char l = '0';
    char *temp = malloc(1000 * sizeof(char));
    strcpy(temp, anc);
    strncat(temp, &l, 1);
    H_tree_search(temp, Tree->left, ans);
    printf("2");
    strcpy(temp, anc);
    strncat(temp, &r, 1); 
    H_tree_search(temp, Tree->right, ans);
    printf("3");
}   