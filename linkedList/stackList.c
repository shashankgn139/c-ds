#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack node;
node *start = NULL;

void push()
{
    // making node
    node *n_node = (node *)malloc(sizeof(node));
    if (n_node == NULL)
    {
        printf("Insufficient memory !\n");
        return;
    }
    printf("Enter the data:");
    scanf("%d", &n_node->data);
    n_node->next = NULL;
    // pushing node
    if (start == NULL)
    {
        start = n_node;
        return;
    }
    n_node->next = start;
    start = n_node;
}

void pop() // similar to delete front function
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

void display()
{
    node *temp = start;
    if (start == NULL)
    {
        printf("empty stack\n");
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
        printf("1.push, 2.pop, 3.display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}