/*
*Given an array of elements, construct a complete binary tree from this array in level
*order fashion.That is ,elements from left in the array will be filled in the tree level wise
*starting from level 0.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct bt {
        int info;
        struct bt *lptr, *rptr;
} node;

node *queue[MAX];
int f = 0, r = -1, ct = 0;

void enque(node *ele)
{
        r = (r + 1) % MAX;
        ct++;
        queue[r] = ele;
}

node *deque()
{
        int tmp = f;
        f = (f + 1) % MAX;
        ct--;
        return queue[tmp];
}

node *getnode(int data)
{
        node *new1 = malloc(sizeof(node));
        new1->lptr = new1->rptr = NULL;
        new1->info = data;
        return new1;
}

node *createLevelorder(node *root, int a[], int n)
{
        node *temp;
        int i = 0;
        root = getnode(a[i++]);
        enque(root);
        while (i < n) {
                temp = deque();
                temp->lptr = getnode(a[i++]);
                if (i < n)                              //this because the program malfunctions 
                        temp->rptr = getnode(a[i++]);   //for even number of elements
                enque(temp->lptr);
                enque(temp->rptr);
        }
        return root;
}

void levelOrderDisplay(node *root)
{
        node *temp;
        f = 0;
        r = -1;
        ct = 0;
        enque(root);
        while (ct != 0) {
                temp = deque();
                printf("%d ", temp->info);
                if (temp->lptr)
                        enque(temp->lptr);
                if (temp->rptr)
                        enque(temp->rptr);
        }
}

void inorder(node *root)
{
        if (root != NULL) {
                inorder(root->lptr);
                printf("%d ", root->info);
                inorder(root->rptr);
        }
        
}

void main()
{
        int n, a[20];
        node *root = NULL;
        printf("Ennter the number of array elements : ");
        scanf("%d", &n);
        printf("\nenter the array elements\n");
        for(int i = 0; i < n; i++)
                scanf("%d", &a[i]);
        printf("\nlevel order tree\n");
        root = createLevelorder(root, a, n);
        printf("\n");
        inorder(root);
        printf("\n");
        levelOrderDisplay(root);
        
}