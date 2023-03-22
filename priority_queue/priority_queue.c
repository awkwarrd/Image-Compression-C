#include "priority_queue.h"

void swap(bt *first, bt *second)
{
    bt temp = *first;
    *first = *second;
    *second = temp;
}

queue create()
{
    queue temp;
    temp.size = 0;
    for (int i = 0; i < 1000; i++)
        temp.array[i] = NULL;

    return temp;    
}

void heapify(bt *array[], int size, int i)
{
    if (size > 1)
    {
        int lowest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && array[left]->value < array[lowest]->value)
            lowest = left;
        if (right < size && array[right]->value < array[lowest]->value)
            lowest = right;

        if (lowest != i)
        {
            swap(&array[i], &array[lowest]);
            heapify(array, size, lowest);
        }  
    }
}

void insert(bt *array[], int *size, bt new_node) 
{
    if (size == 0) {
        array[0] = new_node;
        size += 1;
    } 
    else
    {
        array[size] = new_node;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(array, size, i);    
    }
}


void kill(bt array[], int size)
{
    swap(&array[0], &array[size - 1]);
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);   
}


void print_queue(bt array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        print_tree(array[i]); 
        printf("\n");
    }
     
}