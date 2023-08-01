#include <stdio.h>
#include <stdlib.h>

// declaration of doubly linked lists
struct ListNode
{
    int data;
    struct ListNode *prev;
    struct ListNode *next;
};



struct ListNode *head = NULL;

void insertAtHead(int data)
{
    struct ListNode *temp;
    // initializing new node with the help of malloc
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

void insertAtIntermediate(int data, int position)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));

    // checking for memory errors
    if (!temp)
    {
        printf("Memory error");
        return;
    }

    // creating new copy of head to traverse through the whole list
    struct ListNode *headCopy = head;

    // assigning data provided to newly created node
    temp->data = data;

    // checking if list exists
    if (head == NULL)
    {
        printf("List does not exist. Creating new List");
        temp->next = NULL;
        temp->prev = NULL;
    }

    int i = 0;

    // traversing through the list to n-1 node
    while (i != position - 1)
    {
        headCopy = headCopy->next;
        i++;
    }

    // changing next of newly created node to current n-1 node's next
    temp->next = headCopy->next;

    // changing next of current n-1 node's next to newly created node's address
    headCopy->next = temp;

    // changing prev of newly created node to n-1  node address
    temp->prev = headCopy;
    printf("Success adding node in between");
}

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

void deleteIntermediateNode(int position)
{
    int i = 0;
    struct ListNode *headCopy = head;
    struct ListNode *prev, *next;
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

void print()
{
    struct ListNode *headCopy = head;
    while (headCopy->next == NULL)
    {
        printf("\n %d ", headCopy->data);
        headCopy = headCopy->next;
    }
}

int main(int argc, char const *argv[])
{
    insertAtHead(1);
    insertAtLast(2);
    insertAtIntermediate(3, 1);
    deleteHeadNode();
    // deleteTailNode();
    // deleteIntermediateNode(0);
    // fix these funuctions
    print();
}
