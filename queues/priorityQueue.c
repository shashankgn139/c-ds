#include <stdio.h>
#include <stdlib.h>
typedef struct dll
{
        int data;
        struct dll *lptr, *rptr;
} node;
node *PriorityQ(int a[])
{
        node *start = NULL;
        for (int i = 0; i < 5; i++)
        {
                node *nNode = malloc(sizeof(node));
                nNode->lptr = nNode->rptr = NULL;
                nNode->data = a[i];
                node *temp = start;
                if (start == NULL || nNode->data < start->data)
                {
                        nNode->rptr = start;
                        start = nNode;
                }
                else
                {
                        while (temp->rptr != NULL && temp->rptr->data <= nNode->data)
                        {
                                temp = temp->rptr;
                        }
                        nNode->rptr = temp->rptr;
                        temp->rptr = nNode;
                }
        }
}
void main()
{
        int a[] = {5, 4, 3, 2, 1};
        node *start = PriorityQ(a);
        node *temp = start;
        while (temp != NULL)
        {
                printf("%d ", temp->data);
                temp = temp->rptr;
        }
}
