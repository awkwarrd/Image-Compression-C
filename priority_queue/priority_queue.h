#include <stdio.h>
#include <stdlib.h>

#include "../binary_tree/binary_tree.h"

// priority queue
typedef struct priority_queue
{
    int size;
    bt array[2000];
} queue;

//create empty queue
queue create();

//swap to element
void swap(bt *first, bt *second);

// heapify priority queue
void heapify(queue *q, int i);

// insert new element into queue
void insert(queue *q, bt new_node);

// delete root element from queue
bt kill(queue *q);

// print priority queue
void print_queue(queue q);