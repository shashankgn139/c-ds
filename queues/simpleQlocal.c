// ordinary queue using local variables
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void enque(int a[], int *r)
{
    int item;
    if (*r == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the item\n");
    scanf("%d", &item);
    a[++(*r)] = item;
}

void deque(int a[], int *r, int *f)
{
    if (*f > *r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Deleted item is: %d\n", a[(*f)++]);
}

void display(int a[], int r, int f)
{
    if (f > r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("contents of the queue is: \n");
    for (int i = f; i <= r; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main()
{
    int f = 0, r = -1, a[MAX];
    int ch;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1.Insert   2.Delete   3.Display   4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque(a, &r);
            break;
        case 2:
            deque(a, &r, &f);
            break;
        case 3:
            display(a, r, f);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}