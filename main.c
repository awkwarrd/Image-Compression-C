#include <stdlib.h>
#include <stdio.h>

#include "convertation/convertation.h"
#include "binary_tree/binary_tree.h"

int main(int argc, char* argv[])
{
    bt root = create(8, 'x');
    root->left = create(6, 'o');
    root->right = create(10, 'p');

    bt second_root = create(16, 'l');
    second_root->left = create(13, 'u');
    second_root->right = create(20, 'n');

    bt temp = merge(second_root, root);
    print_tree(temp);
    printf("\n");
    return 0;
}