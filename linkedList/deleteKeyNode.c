/*program to delete all the occurances in a linked list*/
#include <stdio.h>
#include <stdlib.h>
struct dll
{
        int data;
        struct dll *rptr, *lptr;
};
typedef struct dll node;
node *start = NULL;

/*display function displays list elements
 */
void display()
{
        node *temp = start;
        if (start == NULL)
        {
                printf("list is empty\n");
                return;
        }
        printf("list: ");
        while (temp != NULL)
        {
                printf("%d ", temp->data);
                temp = temp->rptr;
        }
        printf("\n");
}
/*get nodes with n elements in it
 */
void getnodes()
{
        printf("How many nodes? :  ");
        int n;
        scanf("%d", &n);
        while (n--)
        {
                node *new1 = (node *)malloc(sizeof(node));
                printf("Enter info: ");
                scanf("%d", &new1->data);
                new1->rptr = NULL;
                node *temp = start;
                if (start == NULL)
                {
                        start = new1;
                }
                else
                {
                        while (temp->rptr != NULL)
                                temp = temp->rptr;
                        temp->rptr = new1;
                }
                new1->lptr = temp;
        }
}

/*function to delete all the occurances of elements in a given list
 */
void deleteAllOccurances()
{
        // when no list elements are present
        if (start == NULL)
        {
                printf("List is empty\n");
                return;
        }
        int key, flag = 0;
        node *temp = start, *altemp;
        printf("Enter the key element: ");
        scanf("%d", &key);
        while (temp != NULL) // looping for all the elements
        {
                if (temp->data == key)
                {
                        flag = 1;
                        // sigle node-edge case
                        if (start->rptr == NULL)
                        {
                                printf("deleted node is: %d\n", temp->data);
                                free(start);
                                start = NULL; // updating start
                                return;
                        }
                        // FIRST element holds the key-edge case
                        if (temp == start)
                        {
                                printf("deleted node is: %d\n", temp->data);
                                (temp->rptr)->lptr = NULL;
                                start = temp->rptr;
                                free(temp);
                                temp = start;
                                goto here;
                        }
                        // LAST element matches the key-edge case
                        if (temp->rptr == NULL)
                        {
                                printf("deleted node is: %d\n", temp->data);
                                (temp->lptr)->rptr = NULL;
                                free(temp);
                                return; // returning to the fuction because it's the last element anyway
                        }
                        // any other element in between the list-general case
                        printf("deleted node is: %d\n", temp->data);
                        (temp->lptr)->rptr = temp->rptr;
                        (temp->rptr)->lptr = temp->lptr;
                        altemp = temp;
                        temp = altemp->rptr;
                        free(altemp);
                here:
                }
                else
                {
                        temp = temp->rptr;
                }
        }
        if (flag != 1)
                printf("\nunsuccesful search !!!\n");
}

void main()
{
        int ch;
        while (1)
        {
                printf("1.get some nodes\n2.delete the occurances\n");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                        getnodes();
                        display();
                        break;
                case 2:
                        deleteAllOccurances();
                        display();
                        break;
                default:
                        printf("invalid input\nterminating...");
                        exit(0);
                }
        }
}
// deleting first element works perfect
// unsucessful works pefectly fine
// deleting function is perfect