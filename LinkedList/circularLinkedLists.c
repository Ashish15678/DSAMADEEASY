#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

// defining global variable head which points to the head of the List
struct ListNode *head = NULL;
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
        struct ListNode *cur;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
        head = temp;
    }
}

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

int main(int argc, char const *argv[])
{

    return 0;
}
