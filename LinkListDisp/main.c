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
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}
int count(struct Node *p)
{   int l=0;
    while (p)
    {
        l++;
        p=p->next;
    }
    return l;
}
int sum(struct Node *p)
{   int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int main()
{
    
    int A[]={3,5,7,10,15};
    create(A, 5);
    
    //Display(first);
    //RDisplay(first);
    //printf("Count is %d\n",count(first));
    printf("Sum is %d\n",sum(first));
    return 0;
}
