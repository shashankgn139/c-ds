// circular queue using local variables (pointers)
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void enqueue(int a[], int *ct, int *r)
{
    int item;
    if (*ct == MAX)
    {
        printf("Insertion not possible\n");
        return;
    }
    printf("Enter the item\n");
    scanf("%d", &item);
    *r = (*r + 1) % MAX;
    a[*r] = item;
    (*ct)++;
}

void deque(int a[], int *ct, int *f)
{
    if (*ct == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted item is %d\n", a[*f]);
    *f = (*f + 1) % MAX;
    (*ct)--;
}

void display(int a[], int ct, int f)
{
    if (ct == 0)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("contents of the queue are \n");
    while (ct--)
    {
        printf("%d ", a[f]);
        f = (f + 1) % MAX;
    }
    printf("\n");
}

void main()
{
    int ct = 0, a[MAX], f = 0, r = -1, ch;
    while (1)
    {
        printf("Enter the choice\n");
        printf("1.Insert   2.Delete   3.Display   4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(a, &ct, &r);
            break;
        case 2:
            deque(a, &ct, &f);
            break;
        case 3:
            display(a, ct, f);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}