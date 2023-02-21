// ordinary queue using global variables
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int f = 0, r = -1, a[MAX];
void enque()
{
    int item;
    if (r == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the item\n");
    scanf("%d", &item);
    a[++r] = item;
}

void deque()
{
    if (f > r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Deleted item is: %d\n", a[f++]);
}

void display()
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
    int ch;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1.Insert   2.Delete   3.Display   4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}