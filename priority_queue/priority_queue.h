#include <stdio.h>
#include <stdlib.h>

#include "../binary_tree/binary_tree.h"

typedef struct priority_queue
{
    int size;
    bt * array[1000];
} queue;

//create empty queue
queue create();

//swap to element
void swap(bt *first, bt *second);

// heapify priority queue
void heapify(bt array[], int size, int i);

// insert new element into queue
void insert(bt array[], int size, bt new_node);

// delete root element from queue
void kill(bt array[], int size);
''
// print priority queue
void print_queue(bt array[], int size);