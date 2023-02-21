/*basic binary tree functions
 * - inserting node
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include<ctype.h>

struct BT
{
        int data;
        struct BT *lptr, *rptr;
};
typedef struct BT node;

/*function to convert an alphabet to upper case
 * parameters - character for case conversion
 * */
char toUpper(char ch)
{
        if (ch > 'a' && ch < 'z')
                return (ch - 32);
        else
                return ch;
}

/*inserting a node in the function using direction
 * given by user
 * parameters - root node pointer
 * */
node *insertNode(node *root)
{
        node *n_node = malloc(sizeof(node));
        node *cur = root, *prev;
        char d[50];

        n_node->lptr = n_node->rptr = NULL;

        printf("\nData : ");
        scanf("%d", &(n_node->data));
        if (root == NULL)
        {
                printf("-first node\n");
                return n_node;
        }

        printf("Direction : ");
        scanf("%s", d);

        int i;
        for (int i = 0; i < strlen(d) && cur; i++)
        {
                prev = cur;
                if (toUpper(d[i]) == 'L')
                        cur = cur->lptr;
                else
                        cur = cur->rptr;
        }

        if (strlen(d) && cur)
        {
                printf("\n-insertion not possible!\n");
                free(n_node);
                return root;
        }

        if (toUpper(d[i]) == 'L')
                prev->lptr = n_node;
        else
                prev->rptr = n_node;
        return root;
}

/*displaying in INORDER
 * paramaters - address of root node
 * */
void displayInorder(node *root)
{
        if (root)
        {
                displayInorder(root->lptr);
                printf("%d ", root->data);
                displayInorder(root->rptr);
        }
}

void main()
{
        node *root = NULL;
        int n;

        printf("\nEnter the number of nodes : ");
        scanf("%d", &n);
        while (n--)
        {
                root = insertNode(root);
                displayInorder(root);
                printf("\n");
        }
}
/*INPUT
 *
 * */