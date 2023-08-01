# Stacks

## Why stacks?

`Stacks are used in multiple data structures and has countless applications , therefore stacks.`
` It has LIFO / FILO type which is Last in First out or First in Last out.

## Implementation :

`Three methods`

1. Using arrays
2. Using dynamic arrays(growable arrays)
3. Using Linked List

### Implementation using Arrays

### Implementation using Linked list

1. First create a new data type Linked List having data and pointer to the next Node.

```c
struct listNode
{
    int data;
    struct listNode *next;
};

```

2. Then create a new data type Stack which will have only one pointer of Linked list type which will always point to the top of the Stack.

```c
struct Stack{
    struct listNode *top;
};
```

3. Create createStack function in order to initialize Stack

```c
struct Stack *createStack()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
```

4. Creating All other necessary Functions used in stack
