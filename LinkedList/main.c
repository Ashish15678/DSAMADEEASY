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
void printFirstElement()
{
    /// since head points to first element
    printf("%d", head->data);
}

void printWholeList()
{
    struct ListNode *temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

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

void insertInBetween(int data, int position)
{
    struct ListNode temp;
    struct ListNode *nodeToChange;
    nodeToChange = head;
    int i = 0;
    while (i != position - 1)
    {
        nodeToChange = nodeToChange->next;
    }

    // sets data to our temporary variable
    temp.data = data;

    // changes next of our temporary variable to the nth node's address using n-1 node
    temp.next = nodeToChange->next;

    // finally changes n-1 node's next to our temporary variable's address
    nodeToChange->next = &temp;
}

void deleteFirstNode()
{
    struct ListNode *temp;
    temp = head;
    head = temp->next;
    free(temp);
}

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

int main(int argc, char const *argv[])
{
    insertAtBeginning(5);
    insertAtBeginning(6);
    insertAtBeginning(7);
    deleteFirstNode();
    // insertAtLast(1);
    printFirstElement();
    printWholeList();
    return 0;
}
