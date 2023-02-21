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

node *getNnodes(node *start)
{
    int n;
    printf("\nenter the number of nodes:\n");
    scanf("%d", &n);
    while (n--)
    {
        node *n_node = (node *)malloc(sizeof(node));
        printf("enter data: ");
        scanf("%d", &n_node->data);
        n_node->rptr = start;
        start = n_node;
    }
    start->lptr = NULL;
    display(start);
    return start;
}

node *catDll(node *start1, node *start2)
{
    node *temp = start1;
    while (temp->rptr != NULL)
        temp = temp->rptr;
    temp->rptr = start1;
    start2->lptr = temp;
    display(start1);
    return start1;
}

void main()
{
    int ch;
    node *start1, *start2;
    while (1)
    {
        printf("1.Get first list   2.Get second list   3.concatenate: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start1 = getNnodes(start1);
            break;
        case 2:
            start2 = getNnodes(start2);
            break;
        case 3:
            catDll(start1, start2);
            break;
        default:
            printf("invalid input");
            exit(0);
        }
    }
}