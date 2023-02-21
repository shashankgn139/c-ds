// ordinary queue using local variables
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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

void enque(int a[], int *r, int *f)
{
        int item, j = *r;
        if (*r == MAX - 1)
        {
                return;
        }
        printf("Enter the item\n");
        scanf("%d", &item);
        while (item < a[j] && *f >= 0)
        {
                a[j + 1] = a[j];
                j--;
        }
        a[++(j)] = item;
        (*r)++;
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
                        enque(a, &r, &f);
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