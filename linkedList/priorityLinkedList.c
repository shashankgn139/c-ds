#include <stdio.h>
#include <stdlib.h>

typedef struct DLL
{
	int data;
	struct DLL *lptr, *rptr;
} node;

/*
priority q sorting the elements in ascending order
parameters - start of list, address of new node
*/
node *priorityQ(node *start, node *nNode)
{
	if (start == NULL)
		start = nNode;

	// insert at front i.e., the least data element
	else if (nNode->data < start->data)
	{
		nNode->rptr = start;
		start->lptr = nNode;
		start = nNode;
	}

	// general case i.e., in between
	else
	{
		node *temp = start;
		while (temp->rptr != NULL && temp->rptr->data < nNode->data)
			temp = temp->rptr;
		nNode->lptr = temp;
		nNode->rptr = temp->rptr;

		// last node
		if (temp->rptr != NULL)
			temp->rptr->lptr = nNode;
		temp->rptr = nNode;
	}
	return start;
}

void displayList(node *start)
{
	if (!start)
	{
		printf("\nempty list\n");
		return;
	}
	while (start)
	{
		printf("%d ", start->data);
		start = start->rptr;
	}
}

int main()
{
	node *start = NULL;
	int a[] = {2, 78, 98, 83, 67, 53, 77, 2};
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		node *nNode = malloc(sizeof(node));
		nNode->lptr = nNode->rptr = NULL;
		nNode->data = a[i];
		start = priorityQ(start, nNode);
	}
	displayList(start);
	return 0;
}