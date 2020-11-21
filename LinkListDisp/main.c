#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node * next;
}*first=NULL;        //global variable

// Creating a linked list
void create(int A[],int n )
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last = t;
    }
    
}
int main()
{
    
    int A[]={3,5,7,10,15};
    create(A, 4);
    
    return 0;
}
