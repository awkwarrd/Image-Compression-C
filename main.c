#include <stdlib.h>
#include <stdio.h>

#include "convertation/convertation.h"
#include "priority_queue/priority_queue.h"

int main(int argc, char* argv[])
{
    bt first_root = create(8, 'x');
    first_root->left = create(6, 'o');
    first_root->right = create(10, 'p');

    bt second_root = create(16, 'l');
    second_root->left = create(13, 'u');
    second_root->right = create(20, 'n');

    bt third_root = create(26, 'g');
    third_root -> left = create(22, 'y');
    third_root -> right = create(30, 'f');

    print_queue q = create();
    int size = 0;
    insert(queue, size, first_root);
    insert(queue, size, second_root); 
    insert(queue, size, third_root);

    printf("%d\n", size);
    print_queue(queue, size);
    return 0;
    
}

