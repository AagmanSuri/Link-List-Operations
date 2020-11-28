#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node// The structure
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
        last = t;//last should move on to t and t should make a new node
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
int Rsum(struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next)+p->data;
    }
}
int max(struct Node *p)
{
    int m =INT32_MIN;//-32768
    while(p)
    {
        if(p->data>m)
        {
            m=p->data;
        }
        p=p->next;
    }
    return m;
}

struct Node * Lsearch(struct Node *p, int key )
{
    struct Node *q=NULL;
    
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next; //Method to bring it on the front
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
void Insert(struct Node *p,int pos)
{
//    if()
}
int main()
{
    
    int A[]={3,5,7,70,15};
    create(A, 5);
    struct Node *temp;
    temp=Lsearch(first,7);
    //Display(first);
    //RDisplay(first);
    //printf("Count is %d\n",count(first));
    //printf("Sum is %d\n",sum(first));
    //printf("The sum is %d",Rsum(first));
    //printf("The maximum is %d",max(first));
    if(temp)
    {
        printf("key is found  %d",temp->data);
    }
    else
    {
        printf("Key not found");
        
    }
    Display(first);
    return 0;
    
}
