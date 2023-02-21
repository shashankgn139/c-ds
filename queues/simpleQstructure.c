// ordinary queue using structures
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct queue
{
    int f;
    int r;
    int a[MAX];
};
typedef struct queue qu;
void enque(qu *q)
{
    int item;
    if (q->r == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the item\n");
    scanf("%d", &item);
    q->a[++(q->r)] = item;
}

void deque(qu *q)
{
    if (q->f > q->r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Deleted item is: %d\n", q->a[(q->f)++]);
}

void display(qu *q)
{
    if (q->f > q->r)
    {
        printf("Queue empty\n");
        return;
    }
    printf("contents of the queue is: \n");
    for (int i = q->f; i <= q->r; i++)
    {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

void main()
{
    qu q;
    q.f = 0;
    q.r = -1;
    int ch;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1.Insert   2.Delete   3.Display   4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque(&q);
            break;
        case 2:
            deque(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}