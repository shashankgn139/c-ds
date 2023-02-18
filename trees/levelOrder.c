#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct BinarySearchTree
{
        int info;
        struct BinarySearchTree * lptr, * rptr;
};
typedef struct BinarySearchTree node;
//queue Implementaion
int f = 0, r = -1, count = 0;
node * q[SIZE]; //#define SIZE 10
void enqueue(node * address){
        r = (r + 1) % SIZE;
        q[r] = address;
        count++;
}
node * dequeue() {
        int preF = f;
        f = (f + 1) % SIZE;
        count--;
        return q[preF];
}

node * getnode(int data) {
        node * new1 = malloc(sizeof(node));
        new1->info=data;
        new1 -> lptr = new1 -> rptr = NULL;
        return new1;
}
node* lvlotree(node* root, int a[],int n) {
        node * temp;
        int i=0;
        root = getnode(a[i++]);
        enqueue(root);
        while(i<n)
        {
                temp = dequeue();
                temp -> lptr = getnode(a[i++]);
                temp -> rptr = getnode(a[i++]);
                enqueue(temp -> lptr);
                enqueue(temp -> rptr);
        }
        return root;
}

void levelorderTraversal(node * rootL) {
        f = 0;
        r = -1;
        count = 0;
        node * temp;
        enqueue(rootL);
        do {
                temp = dequeue(); //copied
                printf("%d  ", temp -> info);
                if (temp -> lptr) //GN's
                        enqueue(temp -> lptr);
                if (temp -> rptr) //logic
                        enqueue(temp -> rptr);
        } while (count > 0);
}

void main() {
        node * root = NULL;
        int a[] = {1,2,3,4,5,6,7};
        int n=sizeof(a)/sizeof(a[0]);
        root = lvlotree(root, a ,n);
        printf("Expected output:\n");
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
                printf("%d  ",a[i]);
        printf(" \n");
        printf("Level order output after tree generation:\n");
        levelorderTraversal(root);
        printf("\n");
}