#include <stdio.h>
#include <stdlib.h>
struct lists
{
    int data;
    struct lists *next;
};
typedef struct lists node;
node *start = NULL;

node *getnode()
{
    node *n_node = (node *)malloc(sizeof(node));
    if (n_node == NULL)
    {
        printf("insufficient memory!!\n");
        exit(0);
    }
    printf("Eneter the data");
    scanf("%d", &n_node->data);
    n_node->next = NULL;
    return n_node;
}

void insertFront()
{
    node *n_node = getnode();
    if (start == NULL)
    {
        start = n_node;
        return;
    }
    n_node->next = start;
    start = n_node;
}

void deleteFront()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("Empty stack\n");
        return;
    }
    if (start->next == NULL)
    {
        printf("popped element is %d", start->data);
        free(start);
        start = NULL;
    }
    printf("popped item is %d\n", temp->data);
    start = temp->next;
    free(temp);
}

void insertRear()
{
    node *temp = start;
    node *n_node = getnode();
    if (start == NULL)
    {
        start = n_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n_node;
}

void deleteRear()
{
    node *temp = start, *prev;
    if (start == NULL)
    {
        printf("Empty stack\n");
        return;
    }
    if (start->next == NULL)
    {
        printf("popped element is %d", start->data);
        free(start);
        start = NULL;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    printf("deleted element is %d", temp->data);
    free(temp);
    prev->next = NULL;
}

void display()
{
    node *temp = start;
    if (start = NULL)
    {
        printf("LIst empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int ch;
    while (1)
    {
        printf("1.InsertFront   2.InsertRear   3.DeleteFront  4.DeleteRear   5.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertRear();
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        default:
            printf("invalid choice\nterminating\n");
            exit(0);
        }
    }
}