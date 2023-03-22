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

bt b_create(int value, char symbol)
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
    bt temp = create(first->value + second->value, '.');
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