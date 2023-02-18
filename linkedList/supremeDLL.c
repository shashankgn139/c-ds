/*DOUBLY LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>
struct dll
{
        int data;
        struct dll *rptr,*lptr;
};
typedef struct dll node;
node* start=NULL;

/*display list function*/
void display()
{
        node *temp=start;
        if(start==NULL)
        {
                printf("list is empty\n");
                return;
        }
        printf("list: ");
        while(temp!=NULL)
        {
                printf("%d ",temp->data);
                temp=temp->rptr;
        }
        printf("\n");
}

/*gets just one node*/
node* getnode()
{
        node* n_node=(node*)malloc(sizeof(node));
        if(n_node==NULL)
        {
                printf("insufficient memory!");
                exit(0);
        }
        printf("enter data: ");
        scanf("%d",&n_node->data);
        start=n_node;
        n_node->lptr=NULL;
        n_node->rptr=NULL;
        return n_node;
}

/*get nodes with 'n' elements in it
 * inserting new elements at the end of the list
 */
void getnodes()
{
        printf("How many nodes? :  ");
        int n;
        scanf("%d", &n);
        while(n--)
        {
                node* new1=(node*)malloc(sizeof(node));
                printf("Enter info: ");
                scanf("%d",&new1->data);
                new1->rptr=NULL;
                node* temp=start;
                if(start==NULL)
                {
                        start=new1;
                }
                else
                {
                        while(temp->rptr!=NULL)
                                temp=temp->rptr;
                        temp->rptr=new1;
                }
                new1->lptr=temp;
        }
}

/*inserts new node towards the 'start' of the list
 * also reassings the start*/
void insertFront()
{
        node* n_node=getnode();
        n_node->rptr=start;
        start=n_node;
}

/*inserts new node towards the end of the list*/
void insertRear()
{
        node* temp=start;
        node* n_node=getnode();
        if(start==NULL)
        {
                start=n_node;
                return;
        }
        while(temp->rptr!=NULL)
                temp=temp->rptr;
        n_node->lptr=temp;
        temp->rptr=n_node;
}

/*deleting 'start' of the list
 * also reassigns the start*/
void deleteFront()
{
        node* temp=start;
        if(start==NULL)
        {
                printf("empty list\n");
                return;
        }
        if(start->rptr==NULL)
        {
                printf("deleted element is: %d\n",start->data);
                free(start);
                start=NULL;
                return;
        }
        printf("deleted element is: %d\n",start->data);
        start=start->rptr;
        free(temp);
}

/*deleting the last element of the list*/
void deleteRear()
{
        node* temp=start;
        if(start==NULL)
        {
                printf("emtpy list\n");
                return;
        }
        if(start->rptr==NULL)
        {
                printf("deleted element is %d\n",start->data);
                free(start);
                start=NULL;
                return;
        }
        while(temp->rptr==NULL)
                temp=temp->rptr;
        printf("deleted element is %d\n",temp->data);
        (temp->lptr)->rptr=NULL;
        free(temp);
}


void main()
{
        int ch;
        while(1)
        {
                printf("1.Insert 'n' nodes\n2.Insert Front\n3.Insert Rear\n4.Delete Front\n5.Delete Rear\n6.Delete 'key' element from the list\n7.Reverse List\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:break;
                        case 2:break;
                        case 3:break;
                        case 4:break;
                        case 5:break;
                        case 6:break;
                        case 7:break;
                        default:printf("Invalid input!!!\nTerminating..");
                        exit(0);

                }
        }
}