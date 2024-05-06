#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct
{
    int *items;
    int top;
    int capacity;
} t_stack;

t_stack *createStack(int capacity);
void freeStack(t_stack *stack);
bool push(t_stack *stack, int item);
int pop(t_stack *stack);
bool isEmpty(t_stack *stack);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSortIterative(int arr[], int l, int h);

#endif