#include<stdio.h>
#include<stdlib.h>

struct BST {
    int data;
    struct BST *lptr, *rptr;
};
typedef struct BST node;

/*insertion of a node in Binary Search Tree
 * paramaters - address of root node pointer(&root), interger data
 * */
void insertNode(node **root, int info) {
        node *cur = *root, *prev = NULL;
        node *n_node = (node *) malloc(sizeof(node));
        n_node->data = info;
        n_node->lptr = n_node->rptr = NULL;
        if (*root == NULL) {
                *root = n_node;
                return;
        }
        while (cur != NULL) {
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

/*inorder dispaly funciton
 * parameters - root node of any binary tree
 * */
void displayInorder(node *root) {
        if (root != NULL) {
                displayInorder(root->lptr);
                printf("%d ", root->data);
                displayInorder(root->rptr);
        }
}


/*preorder dispaly funciton
 * parameters - root node of any binary tree
 * */
void displayPreorder(node *root) {
        if (root != NULL) {
                printf("%d ", root->data);
                displayPreorder(root->lptr);
                displayPreorder(root->rptr);
        }
}


/*postorder dispaly funciton
 * parameters - root node of any binary tree
 * */
void displayPostorder(node *root) {
        if (root != NULL) {
                displayPostorder(root->lptr);
                displayPostorder(root->rptr);
                printf("%d ", root->data);
        }
}


int main() {
        node *root = NULL;
        int a[] = {20, 30, 15, 5, 40, 50, 10};
        for (int i = 0; i < 7; ++i)
                insertNode(&root, a[i]);
        displayInorder(root);
        printf("Enter key to be deleted: \n");
        scanf("%d", &key);
        return 0;
}