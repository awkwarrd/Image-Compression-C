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

void heapify(queue *q, int i)
{
    if (q->size > 1)
    {
        int lowest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < q->size && q->array[left]->value < q->array[lowest]->value)
            lowest = left;
        if (right < q->size && q->array[right]->value < q->array[lowest]->value)
            lowest = right;

        if (lowest != i)
        {
            swap(&q->array[i], &q->array[lowest]);
            heapify(q, lowest);
        }  
    }
}

void insert(queue *q, bt new_node) 
{
    if (q->size == 0) {
        q->array[0] = new_node;
        q->size += 1;
    } 
    else
    {
        q->array[q->size] = new_node;
        q->size += 1;
        for (int i = q->size / 2 - 1; i >= 0; i--)
            heapify(q, i);    
    }
}


bt kill(queue *q)
{
    bt temp = q->array[0];
    swap(&q->array[0], &q->array[q->size - 1]);
    q->size--;
    for (int i = q->size / 2 - 1; i >= 0; i--)
        heapify(q, 0);   
    
    return temp;
}


void print_queue(queue q)
{
    for (int i = 0; i < q.size; i++)
    {
        print_tree(q.array[i]); 
        printf("\n");
    }
}