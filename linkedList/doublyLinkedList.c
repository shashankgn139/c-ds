// all doubly linked lit operations
#include <stdio.h>
#include <stdlib.h>
struct dll
{
    int data;
    struct dll *rptr, *lptr;
};
typedef struct dll node;

void display(node *start)
{
    node *temp = start;
    if (start == NULL)
    {
        printf("list is empty\n");
        return;
    }
    printf("list elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->rptr;
    }
    printf("\n");
}

node *getnode(node *start) // get new node
{
    node *n_node = (node *)malloc(sizeof(node));
    if (n_node == NULL)
    {
        printf("insufficient memory!");
        exit(0);
    }
    printf("enter data: ");
    scanf("%d", &n_node->data);
    start = n_node;
    n_node->lptr = NULL;
    n_node->rptr = NULL;
    return n_node;
}

node *insertFront(node *start)
{
    node *n_node = getnode(start);
    n_node->rptr = start;
    start = n_node;
    display(start);
    return start;
}

node *insertRear(node *start) // return type void can also be used
{
    node *temp = start;
    node *n_node = getnode(start);
    if (start == NULL)
    {
        start = n_node;
        return start;
    }
    while (temp->rptr != NULL)
        temp = temp->rptr;
    n_node->lptr = temp;
    temp->rptr = n_node;
    display(start);
    return start; // when return type void is used you can remove this line
}

node *deleteFront(node *start)
{
    node *temp = start;
    if (start == NULL)
    {
        printf("empty list\n");
        return start;
    }
    if (start->rptr == NULL)
    {
        printf("deleted element is %d\n", start->data);
        free(start);
        start = NULL;
        return start;
    }
    printf("deleted element is %d\n", start->data);
    start = start->rptr;
    free(temp);
    display(start);
    return start;
}

node *deleteRear(node *start)
{
    node *temp = start;
    if (start == NULL)
    {
        printf("emtpy list\n");
        return start;
    }
    if (start->rptr == NULL)
    {
        printf("deleted element is %d\n", start->data);
        free(start);
        start = NULL;
        return start;
    }
    while (temp->rptr == NULL)
        temp = temp->rptr;
    printf("deleted element is %d\n", temp->data);
    (temp->lptr)->rptr = NULL;
    free(temp);
    display(start);
    return start;
}

void main()
{
    int ch;
    node *start;

    while (1)
    {
        printf("1.Insert Front    2.Insert Rear    3.Delete Front    4.Delete Rear: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = insertFront(start);
            break;
        case 2:
            start = insertRear(start);
            break;
        case 3:
            start = deleteFront(start);
            break;
        case 4:
            start = deleteRear(start);
            break;
        default:
            printf("\ninvalid option\nterminating...");
            exit(0);
        }
    }
}