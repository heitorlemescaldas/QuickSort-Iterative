#include "stack.h"
#include <stdlib.h>

/*
A estratégia iterativa do algoritmo Quicksort, como implementada aqui, faz uso eficiente da pilha. 
Ao contrário da versão recursiva, que pode adicionar chamadas de função à pilha de execução de forma 
potencialmente desbalanceada, essa implementação iterativa controla explicitamente o que é colocado na 
pilha. Antes de empurrar os índices das partições para a pilha, a implementação poderia ser ajustada 
para verificar o tamanho dessas partições, inserindo primeiro a partição maior. Isso ajuda a reduzir a 
profundidade máxima da pilha, mantendo-a na ordem de O(log(n)) em cenários ideais, onde o lado menor é 
processado primeiro, reduzindo assim a probabilidade de atingir a profundidade máxima da pilha.

Entretanto, observa-se que a implementação atual não possui um mecanismo para priorizar a inserção da 
partição maior antes da menor. Isso é uma otimização possível que pode ser considerada para melhorar 
ainda mais a eficiência do uso da pilha.
*/

t_stack *createStack(int capacity)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->items = (int *)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void freeStack(t_stack *stack)
{
    free(stack->items);
    free(stack);
}

bool push(t_stack *stack, int item)
{
    if (stack->top >= stack->capacity - 1)
        return false;
    stack->items[++stack->top] = item;
    return true;
}

int pop(t_stack *stack)
{
    if (stack->top == -1)
        return -1;
    return stack->items[stack->top--];
}

bool isEmpty(t_stack *stack)
{
    return stack->top == -1;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortIterative(int arr[], int l, int h)
{
    t_stack *stack = createStack(h - l + 1);

    push(stack, l);
    push(stack, h);

    while (!isEmpty(stack))
    {
        h = pop(stack);
        l = pop(stack);

        int p = partition(arr, l, h);

        if (p - 1 > l)
        {
            push(stack, l);
            push(stack, p - 1);
        }
        if (p + 1 < h)
        {
            push(stack, p + 1);
            push(stack, h);
        }
    }

    freeStack(stack);
}