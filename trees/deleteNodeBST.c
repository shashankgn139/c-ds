#include <stdio.h>
#include <stdlib.h>
struct BST
{
        int data;
        struct BST *lptr, *rptr;
};
typedef struct BST node;

node *root = NULL;
/*insertion of a node in Binary Search Tree
 * paramaters - interger data
 * */
void insertNode(int info)
{
        node *cur = root, *prev = NULL;
        node *n_node = (node *)malloc(sizeof(node));
        n_node->data = info;
        n_node->lptr = n_node->rptr = NULL;
        if (root == NULL)
        {
                root = n_node;
                return;
        }
        while (cur != NULL)
        {
                prev = cur;
                if (n_node->data < cur->data)
                        cur = cur->lptr;
                else
                        cur = cur->rptr;
        }
        if (n_node->data < prev->data)
                prev->lptr = n_node;
        else
                prev->rptr = n_node;
}

/*finds inorder successor of a given tree
 * parameters - root node pointer*/
node *minValueNode(node *no)
{
        node *current = no;
        while (current->lptr != NULL)
                current = current->lptr;
        return current;
}

/*deletes node in a Binary Search Tree
 * parameters - root node pointer, integer key to be deleted
 * */
node *deleteNode(node *subRoot, int key)
{
        if (subRoot == NULL)
                return subRoot;
        if (key < subRoot->data)
                subRoot->lptr = deleteNode(subRoot->lptr, key);
        else if (key > subRoot->data)
                subRoot->rptr = deleteNode(subRoot->rptr, key);
        else
        {
                if (subRoot->lptr == NULL)
                {
                        node *temp = subRoot->rptr;
                        free(subRoot);
                        return temp;
                }
                else if (subRoot->rptr == NULL)
                {
                        node *temp = subRoot->lptr;
                        free(subRoot);
                        return temp;
                }
                node *temp = minValueNode(subRoot->rptr);
                subRoot->data = temp->data;
                subRoot->rptr = deleteNode(subRoot->rptr, temp->data);
        }
        return subRoot;
}

/*inorder dispaly funciton
 * parameters - root node of any binary tree
 * */
void displayInorder(node *subRoot)
{
        if (subRoot != NULL)
        {
                displayInorder(subRoot->lptr);
                printf("%d ", subRoot->data);
                displayInorder(subRoot->rptr);
        }
}

int main()
{
        int key;
        int a[] = {40, 20, 50, 10, 30, 45, 47};
        for (int i = 0; i < 7; i++)
                insertNode(a[i]);
        displayInorder(root);
        while (1)
        {
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &key);

                root = deleteNode(root, key);

                if (root == NULL)
                        printf("\nelement not found");
                else
                {
                        printf("\nelement deleted succefully: ");
                        displayInorder(root);
                }
        }
        return 0;
}
