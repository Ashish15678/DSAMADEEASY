#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    if (!temp)
    {
        printf("Memory error ... stack not created");
        return;
    }

    temp->capacity = capacity;
    temp->top = -1;
    temp->array = malloc(temp->capacity * sizeof(int));
    if (!temp->array)
        return NULL;
    return temp;
}

int isEmpty(struct Stack *temp)
{
    return (temp->top == -1) ? -1 : 0;
}

int size(struct Stack *temp)
{
    return temp->top + 1;
}

int isFull(struct Stack *temp)
{
    return (temp->top == temp->capacity - 1);
}

void push(struct Stack *temp, int data)
{
    if (isFull(temp))
    {
        printf("Stack overflow");
        return;
    }

    else
    {
        temp->array[++temp->top] = data;
    }
}

int peek(struct Stack *temp)
{
    if (isEmpty(temp))
        return NULL;
    return temp->array[temp->top];
}

void deleteStack(struct Stack *temp)
{
    if (temp)
    {
        if (temp->array)
        {
            free(temp->array);
        }
        free(temp);
    }
}
int pop(struct Stack *temp)
{
    if (isEmpty(temp))
    {
        printf("Stack is empty");
        return;
    }
    else
    {
        return temp->array[--temp->top];
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
