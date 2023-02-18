#include<stdio.h
#include<stdlib.h
#define MAX 5
void main()
{
    int ch;
    while(1)
    {
        printf("1.Insert, 2.Delete, 3.Exit \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insertRear();break;
            case 2: deleteFront();break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}