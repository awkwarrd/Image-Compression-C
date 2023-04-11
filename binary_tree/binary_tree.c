#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "binary_tree.h"

void print_tree(bt root, int level)
{
    if(root != NULL)
    {
        print_tree(root->left, level + 1);
        for(int i = 0; i < level; i++)
            printf("%s", "   ");
        printf("%c\n", root->symbol == 300 ? '{' : root->symbol);
        print_tree(root->right, level + 1);
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
    bt temp = b_create(first->value + second->value, (short)(300));
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

void H_tree_search(char *anc, bt Tree, char *ans[300])
{
    if (Tree->symbol != (short)300)
    {
        strcpy(ans[(int)Tree->symbol],anc);
        return;
    }
    char r = '1';
    char l = '0';
    char *temp = malloc(1000 * sizeof(char));
    strcpy(temp, anc);
    strncat(temp, &l, 1);
    H_tree_search(temp, Tree->left, ans);
    
    strcpy(temp, anc);
    strncat(temp, &r, 1); 
    H_tree_search(temp, Tree->right, ans);
    
    free(temp);
}   