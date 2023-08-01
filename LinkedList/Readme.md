# Linked Lists

## Why Linked lists?

A very simple answer to this question are disadvantages proposed by arrays.Although arrays can be better than linked lists at times so using them wisely is only choice left.

## Declaration of Single-Linked List

```C
struct ListNode{
    int data;   //stores data in that block
    struct ListNode *next; //stores address of next block (if traversing is required)
}
```

## Insertion in the list

`Three possible Cases`

1. Before head(beginning of the list)
   a. create a new node
   b. assign current-head to the next pointer of newly created node
   c. assign address of the newly created node to the head

```C
//assume head as Global Variable
void insertAtBeginning(int data){
 struct ListNode *temp;
 temp = (struct ListNode *)malloc(sizeof(struct ListNode));
 temp->data=data;
 temp->next = NULL;
 if(head = NULL){
    head = temp;
    head->next =  NULL;
 }
 else{
 temp->next = head;
 head = temp;
 }
}
```

2. After the tail(ata the very last)
   a. Find the tail of the list by traversing through the whole list
   b. Create a new temporary node
   c. Assign the next of current tail to our temporary node.

```c
void insertAtLast(int data)
{
    struct ListNode *temp, *cur;
    // creating new temp node
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL; // sets next as NULL
    cur = head;

    // if List is empty
    if (cur == NULL)
    {
        head = temp;
    }
    else
    {
        // find end of the List
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        // now cur is assigned to the last element of List
        cur->next = temp;
    }
}
```

3. Somewhere in between
   a. Find the (n-1) node of the List.
   b. Create a temporary node.
   c. Change current (n-1) node's next to temporary node's address and assign temporary node's next to current nth node.

```c

void insertInBetween(int data, int position)
{
struct ListNode temp;
struct ListNode \*nodeToChange = findNode(position);

    // sets data to our temporary variable
    temp.data = data;

    // changes next of our temporary variable to the nth node's address using n-1 node
    temp.next = nodeToChange->next;

    // finally changes n-1 node's next to our temporary variable's address
    nodeToChange->next = &temp;

}

struct ListNode *findNode(int position)
{
struct ListNode *temp;
temp = head;
// NOTE: only pointer variables have been initialized and not new ListNode type variables so these variables are just pointing , and holding addresses that's all
int i = 0;
while (i != position - 1)
{
temp = temp->next;
i++;
}
return temp;
}
```

## Deletion in Linked Lists

1. Deleting first node in the list
   a. create a temporary node which points at the same place as head
   b. point head to the next element.
   c. Dispose the node which our temporary pointer variable is pointing at.

   ```c


   ```

2. Deletion of last node
   a. Traverse through the whole list and find the last/tail node while keeping track of previous node.
   b. assign the previous node's next to NULL;
   c. free the lsat node.

```c
void deleteLastNode()
{
    if (head == NULL)
        return;
    struct ListNode *prev;
    struct ListNode *temp;
    temp = head;
    while (temp->next != NULL)
    {
        // prev pointer takes care of node before temp pointer
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
```

3. Deletion of intermediate node in the list

   a. Find the node and previous node of that node to be deleted.
   b. assign the next of the node to be deleted to previous node.
   c. free the node to be deleted.

```c

void deleteIntermediateNode(int position)
{
    int i = 0;
    struct ListNode *temp = head;
    struct ListNode *prev;
    if (head == NULL)
    {
        return;
        printf("List is empty");
    }
    while (i != position)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
    printf("SUCCESS!");
}
```

## Traversing the list

1. Start at head node
2. Display / use the elements of Linked List
3. Follow the next pointer until last element has next pointer as null.

# Doubly Linked Lists

## Declaration

```c
struct ListNode{
    int data;
    struct ListNode *prev;
    struct ListNode *next;
}
```

## Insertion

`Three possibilities`

1. Head
2. Tail
3. Intermediate

4. Head
   a. Create a new node and initialize both prev and next as NULL.
   b. update the next to current Head .
   c. assign head to the newly initialized node.

```c

struct ListNode *head = NULL;

void insertAtHead(int data)
{
    struct ListNode *temp;
    initializing new node with the help of malloc
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));

    temp->data = data;
    temp->prev = NULL;
    if (head = NULL)
        temp->next = NULL;
    else
    {
        temp->next = head;
        head = temp;
        printf("Success adding new node with data %d\n", data);
    }
}

```

2. Insert at Tail
   a. Traverse through the whole list and find the last element.
   b. create new node with data provided and assign prev of the new node to the current last node of the list.
   c. change next of the current last node and assign it to the newly created node and finally assign null to the newly created node's next;

```c

void insertAtLast(int data)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *point;
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    head = point;

    // finding tail of the List
    while (point->next = NULL)
    {
        point = point->next;
    }
    point->next = temp;
    temp->prev = point;
}
```

3. Insert at intermediate Position
   a. find n-1 node and nth node
   b. create new temporary node to store data
   c. assign next of newly created node to current n-1 node's next and change next of n-1 node to address of newly created node.
   d. assign address of newly created node to prev of current nth node

```c
void insertAtIntermediate(int data, int position)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));

    //checking for memory errors
    if(!temp) {
        printf("Memory error");
        return;
    }

    //creating new copy of head to traverse through the whole list
    struct ListNode *headCopy = head;

    //assigning data provided to newly created node
    temp->data = data;

    //checking if list exists
    if (head == NULL)
    {
        printf("List does not exist. Creating new List");
        temp->next = NULL;
        temp->prev = NULL;
    }


    int i = 0;

    //traversing through the list to n-1 node
    while (i != position - 1)
    {
        headCopy = headCopy->next;
        i++;
    }

    // changing next of newly created node to current n-1 node's next
    temp->next = headCopy->next;

    // changing next of current n-1 node's next to newly created node's address
    headCopy->next = temp;

    //changing prev of newly created node to n-1  node address
    temp->prev = headCopy;
    printf("Success adding node in between");
}

```

## Deletion

`Three possibilities`

1. Head node
2. Last node
3. intermediate node

### Deletion of head node

1. point head to 2nd node of the list
2. free first node of the list

```c
// deleting head node
void deleteHeadNode()
{
    struct ListNode *temp;

    // checking if list is empty or if does exists
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
}
```

### Deleting Tail Node

1. Traverse through the whole list and find tail node
2. Assign next of n-1 node to NULL
3. free tail node

```c
void deleteTailNode()
{

    // checking if list is empty
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct ListNode *temp = head;
    // prev will take care of n-1 node of the list
    struct ListNode *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
```

### Deletion of Node at intermediate position

1.  void deleteIntermediateNode(int position)
    {
    int i = 0;
    struct ListNode *headCopy = head;
    struct ListNode *prev, \*next;
    if (head == NULL)
    {
    printf("List is empty");
    return;
    }

        // reaching n-1 node
        while (i != position)
        {
            prev = headCopy;
            headCopy = headCopy->next;
            next = headCopy->next;
        }
        prev->next = next;
        next->prev = prev;
        free(headCopy);
        printf("Success");

    }

# Circular Linked Lists

## Declaration

```c
struct ListNode{int data ; struct ListNode *next};
```

## Printing the contents of Circular Linked List

```c
void printList()
{
    // headCopy copies head and then points to all node while traversing the list
    struct ListNode *headCopy = head;

    if (head == NULL)
    {
        printf("List is empty");
    }
    do
    {
        printf("%d", headCopy->data);
        headCopy = headCopy->next;

    } while (headCopy != head);
}

```

## Insertion

`Possibilities`

1. At head position

### At Head

1. Check if head is not null (if list exists).
2. if list exists assign current head to next of newly created node with data provided.
3. if list does not exist , create new temporary node to hold data passed and assign head to the address of newly created node.

```c
void insertAtHead(int data)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));

    // check for memory error
    if (!temp)
    {
        printf("Memory error ... new node not created");
        return;
    }

    temp->data = data;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
        return;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
```

## Deletion

`Possibilities`

1.  Deleting head node

### Deleting Head Node

```c

void deletingHeadNode()
{
    struct ListNode *cur;
    struct ListNode *temp = head;
    head = head->next;
    while (cur->next != temp)
    {
        cur = cur->next;
    }
    cur->next = head;
    free(temp);
}
```

# Very Useful things ahead But ill solve problems first(TODO: COMPLETE THIS ALL)

# Memory efficient Doubly Linked List

## Declaration

```c
struct ListNode {
int data;
struct ListNode *ptrDiff;
};
```
