#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *nodeInit(int a)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = a;
    n->next = NULL;
    return n;
}

void addHead(node **head, int a)
{
    node *n = nodeInit(a);
    if (*head == NULL)
        *head = n;
    else
    {
        n->next = *head;
        *head = n;
    }
}

void addTail(node **head, int a)
{
    node *n = nodeInit(a);
    if (*head == NULL)
        *head = n;
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}

void addAt(node **head, int position, int a)
{
    if (!position)
        addHead(head, a);
    else
    {
        node *n = nodeInit(a);
        node *temp = *head;
        for (int i = 0; i < position - 1; i++)
        {
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void delhead(node **head)
{
    if (*head != NULL)
    {
        node *del = *head;
        *head = (*head)->next;
        free(del);
    }
}

void delTail(node **head)
{
    if (*head != NULL)
    {
        node *temp = *head;
        while (temp->next->next != NULL)
            temp = temp->next;
        node *del = temp->next;
        temp->next = NULL;
        free(del);
    }
}

void deletePos(node **head, int position)
{
    if (position == 0)
        *head = (*head)->next;
    else
    {
        node *temp = *head;
        for (int i = 0; i < position - 1; i++)
        {
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        if (temp->next != NULL)
        {
            node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
    }
}

void out(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
        printf("%d ", i->data);
}

void freeList(node **head)
{
    node *temp = NULL;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    free(*head);
}
