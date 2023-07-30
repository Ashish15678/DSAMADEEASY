## Linked Lists

# Why Linked lists?

A very simple answer to this question are disadvantages proposed by arrays.Although arrays can be better than linked lists at times so using them wisely is only choice left.

# Declaration of Single-Linked List

```C
struct ListNode{
    int data;   //stores data in that block
    struct ListNode *next; //stores address of next block (if traversing is required)
}
```

# Insertion in the list

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
3. Somewhere in between

# Traversing the list

1. Start at head node
2. Display / use the elements of Linked List
3. Follow the next pointer until last element has next pointer as null.
