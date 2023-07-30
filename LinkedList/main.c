#include <stdio.h>
#include <stdlib.h>

// declaration of single Linked List
struct ListNode
{
    int data;              // stores data in that block
    struct ListNode *next; // stores address of next block (if traversing is required)
};

// Globals
struct ListNode *head;

// inserting in Linked list
void insertAtBeginning(int data)
{
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;
    if (head = NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

// traversing the Linked list
void print()
{
    struct ListNode *current = head;
    for (current = head; current != NULL; head = current->next)
    {
        printf("%d", current->data);
    }
}

int main(int argc, char const *argv[])
{
    insertAtBeginning(5);
    insertAtBeginning(6);
    insertAtBeginning(7);
    print();
    return 0;
}
