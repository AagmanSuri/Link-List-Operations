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

void Insert(struct Node *p,int index,int x)
{   int i;
    struct Node *t;
    if(index < 0 || index > count(p))
    {
        return;
    }
    t= (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index ==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=1;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
        
    }
}

void Insertlast(int x)
{
    struct Node *t,*last=NULL;
    t= (struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t,*q=NULL;
    t= (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}
int Delete(struct Node *p,int index)
{
    struct Node *q=q=NULL;
    int x=-1,i;
    if(index<1 || index>count(p))
    {
        return -1;
    }
    else
    {
        if(index==1)
        {
            x=first->data;
            q=first;
            first=first->next;
            free(p);
            return x;
        }
        else
        {
            
            for(i=0;i<index-1;i++)
            {
                q=p;
                p=p->next;
                
            }
            x=p->data;
            q->next=p->next;
            free(p);
            return x;
        }
    }
    
}

int main()
{
    // Uncomment these commands to run the commands
    int A[]={3,5,7,10,14};
    create(A,5);
//    struct Node *temp;
//    temp=Lsearch(first,7);
    //Display(first);
    //RDisplay(first);
    //printf("Count is %d\n",count(first));
    //printf("Sum is %d\n",sum(first));
    //printf("The sum is %d",Rsum(first));
    //printf("The maximum is %d",max(first));
//    if(temp)
//    {
//        printf("key is found  %d",temp->data);
//    }
//    else
//    {
//        printf("Key not found");
//
//    }
    
    //Insert(first,0,10);
    //Insert(first,0,9);
    //Insert(first,0,8);
    //Insertlast(3);
//    SortedInsert(first, 1);
//    SortedInsert(first, 2);
//    SortedInsert(first, 6);
    Delete(first, 1);
    Display(first);
    return 0;
    
}


