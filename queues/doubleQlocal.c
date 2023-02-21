#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void insertFront(int a[], int *f)
{
    int item;
    if (*f == 0)
    {
        printf("INsert from front is not possible\n");
        return;
    }
    printf("Enter item\n");
    scanf("%d", &item);
    a[--(*f)] = item;
}

void deleteRear(int a[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("Deleting from rear not possible\n");
        return;
    }
    printf("Deleted item is %d\n", a[(*r)--]);
}

void insertRear(int a[], int *r)
{
    int item;
    if (*r == MAX - 1)
    {
        printf("INserting from rear not possible\n");
        return;
    }
    printf("Enter the item\n");
    scanf("%d", &item);
    a[++(*r)] = item;
}

void deleteFront(int a[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Deleted item is: %d\n", a[(*f)++]);
}

void display(int a[], int f, int r)
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
    int a[MAX], f = 0, r = -1, ch;
    while (1)
    {
        printf("Enter the choice:\n");
        printf("1.Insert Front   2.Insert Rear   3.Delete Front   4.Delete Rear   5.Display   6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront(a, &f);
            break;
        case 2:
            insertRear(a, &r);
            break;
        case 3:
            deleteFront(a, &f, &r);
            break;
        case 4:
            deleteRear(a, &f, &r);
            break;
        case 5:
            display(a, f, r);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}