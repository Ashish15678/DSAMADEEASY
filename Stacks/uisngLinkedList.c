#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct listNode
{
    int data;
    struct listNode *next;
};

struct Stack
{
    struct listNode *top;
};

struct Stack *createStack()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void push(struct Stack *stack, int data)
{
    struct listNode *temp = malloc(sizeof(struct listNode));
    // checking for memory errors
    if (!temp)
    {
        printf("Memory error ... node not created");
        return;
    }

    if (stack->top == -1)
    {
        stack->top = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = stack->top;
        stack->top = temp;
    }
}

int size(struct Stack *stack)
{
    int counter = 0;
    while (stack->top->next != NULL)
    {
        counter++;
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    struct Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    printf("%d", size(stack));
    return 0;
}
