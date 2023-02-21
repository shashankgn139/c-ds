// addition of polynomial using CSLL and header node
// TODO DONOT DELETE THIS
#include <stdio.h>
#include <stdlib.h>

struct sll
{
        int cf, x, y, z, flag;
        struct sll *next;
};
typedef struct sll node;
node *head1, *head2, *result;

node *getnode(node *head)
{
        node *n_node = (node *)malloc(sizeof(node));
        n_node->next = head;
        return n_node;
}

void display(node *head)
{
        node *temp = head->next;
        if (head->next == head)
        {
                printf("\neqn empty\n");
                return;
        }
        while (temp != head)
        {
                printf(" +(%d) x^%d y^%d z^%d ", temp->cf, temp->x, temp->y, temp->z);
                temp = temp->next;
        }
        printf("\n");
}

void insertRear(node *head, node *n_node)
{
        node *temp = head->next;
        if (head->next == head)
        {
                head->next = n_node;
                return;
        }
        while (temp->next != head)
                temp = temp->next;
        temp->next = n_node;
}

void getpoly(node *head)
{
        int ch;
        do
        {
                node *n_node = getnode(head);
                printf("\nEnter cf, xp, yp, zp\n");
                scanf("%d%d%d%d", &n_node->cf, &n_node->x, &n_node->y, &n_node->z);
                n_node->flag = 0;
                insertRear(head, n_node);
                printf("\nEnter 1 to continue and 0 to stop: ");
                scanf("%d", &ch);
        } while (ch == 1);
}

void addPoly()
{
        node *e1, *e2;
        e1 = head1->next;
        while (e1 != head1)
        {
                e2 = head2->next;
                while (e2 != head2)
                {
                        if (e1->x == e2->x && e1->y == e2->y && e1->z == e2->z && e2->flag == 0)
                        {
                                node *n_node = getnode(result);
                                n_node->cf = (e1->cf) + (e2->cf);
                                n_node->x = e1->x;
                                n_node->y = e1->y;
                                n_node->z = e1->z;
                                n_node->flag = 0;
                                e1->flag = e2->flag = 1;
                                insertRear(result, n_node);
                                break; // exits from inner while loop
                        }
                        e2 = e2->next;
                }
                e1 = e1->next;
        }

        e1 = head1->next;
        while (e1 != head1)
        {
                if (e1->flag == 0)
                {
                        node *t1_node = getnode(result);
                        t1_node->cf = e1->cf;
                        t1_node->x = e1->x;
                        t1_node->y = e1->y;
                        t1_node->z = e1->z;
                        t1_node->flag = 0;

                        e1->flag = 1;
                        insertRear(result, t1_node);
                }
                e1 = e1->next;
        }
        e2 = head2->next;
        while (e2 != head2)
        {
                if (e2->flag == 0)
                {
                        node *t2_node = getnode(result);
                        t2_node->cf = e2->cf;
                        t2_node->x = e2->x;
                        t2_node->y = e2->y;
                        t2_node->z = e2->z;
                        t2_node->flag = 0;

                        e2->flag = 1;
                        insertRear(result, t2_node);
                }
                e2 = e2->next;
        }
}

int main()
{
        head1 = (node *)malloc(sizeof(node));
        head1->next = head1;
        head2 = (node *)malloc(sizeof(node));
        head2->next = head2;
        result = (node *)malloc(sizeof(node));
        result->next = result;

        printf("enter poly 1:");
        getpoly(head1);
        printf("enter poly 2:");
        getpoly(head2);
        display(head1);
        display(head2);
        printf("\npolynomiall addition\n");
        addPoly(head1, head2, result);
        display(result);
        return 0;
}
// printf("\ntest\n");