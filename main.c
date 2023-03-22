#include <stdlib.h>
#include <stdio.h>

#include "convertation/convertation.h"
#include "priority_queue/priority_queue.h"

int main(int argc, char* argv[])
{
    bt first_root = b_create(8, 'x');
    first_root->left = b_create(6, 'o');
    first_root->right = b_create(10, 'p');

    bt second_root = b_create(16, 'l');
    second_root->left = b_create(13, 'u');
    second_root->right = b_create(20, 'n');

    bt third_root = b_create(26, 'g');
    third_root -> left = b_create(22, 'y');
    third_root -> right = b_create(30, 'f');

    queue q = create();
    insert(q, first_root);
    insert(q, second_root); 
    insert(q, third_root);

    printf("%d\n", q.size);
    print_queue(q);
    return 0;
    
}

