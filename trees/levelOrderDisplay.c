#include <stdio.h>
#include <stdlib.h>
#define MAX 25

typedef struct BST
{
        int data;
        struct BST *lptr, *rptr;
} node;

node *insertNode(node *root, int key)
{
        node *cur = root, *prev;
        node *n_node = malloc(sizeof(node));
        n_node->data = key;
        n_node->lptr = n_node->rptr = NULL;
        if (root == NULL)
                return n_node;
        while (cur)
        {
                prev = cur;
                if (key < cur->data)
                        cur = cur->lptr;
                else
                        cur = cur->rptr;
        }
        if (key < prev->data)
                prev->lptr = n_node;
        else
                prev->rptr = n_node;
        return root;
}

/*level-order display
 * parameters - root node address
 * */
void displayLevelorder(node *root)
{
        node *q[MAX];
        int f = 0, r = -1, ct = 0;
        // printf("\n--pushing root\n");
        r = (r + 1) % MAX;
        q[r] = root;
        ct++;

        while (ct)
        {
                // printf("\n--entering while\n");
                root = q[f];
                f = (f + 1) % MAX;
                ct--;
                printf("%d ", root->data);
                if (root->lptr)
                {
                        r = (r + 1) % MAX;
                        ct++;
                        q[r] = root->lptr;
                }
                if (root->rptr)
                {
                        r = (r + 1) % MAX;
                        ct++;
                        q[r] = root->rptr;
                }
        }
}

int main()
{
        node *root = NULL;
        int a[] = {30, 15, 45, 10, 20, 40, 50, 9, 12, 19, 25, 39, 41, 49, 51};
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
                root = insertNode(root, a[i]);
        displayLevelorder(root);
        return 0;
}
/*INPUTS
 * 20, 30, 15, 5, 40, 50, 10
 * 30,15,45,10,20,40,50,9,12,19,25,39,41,49,51
 * */