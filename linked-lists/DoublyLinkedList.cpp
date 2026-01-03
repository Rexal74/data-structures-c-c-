#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
Node *prev;
int data;
Node *next;
}Node;

Node *head=(Node *)malloc(sizeof(Node));

void Create(int A[],int l)
{
    Node *t ,*last;
    head->prev=head->next=NULL;
    head->data=A[0];
    last=head;
    for(int i=1;i<l;i++){
    t=(Node *)malloc(sizeof(Node));
        t->data=A[i];
        last->next=t;
        t->prev=last;
        last=t;
        last->next=NULL;
    }
}
int Length(Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

void Display(Node *p)
{
    while(p)
    {
        printf("%d " ,p->data);
        p=p->next;
    }
}
void Insert(Node *p ,int key ,int index)
{
    Node *t,*q;
    if(index < 0 || index > Length(p)) return;
    if(index == 0)
    {
        if(head == NULL){

            t=(Node *)malloc(sizeof(Node));

             t->data=key;
             t->next=t->prev=NULL;
             head=t;
        }else
        {
            t=(Node *)malloc(sizeof(Node));
            t->data=key;
            t->next=head;
            t->prev=head->prev;
            head->prev=t;
            head=t;
        }

    }else
    {
          t=(Node *)malloc(sizeof(Node));
          t->data=key;
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}

int Delete(Node *p ,int index)
{
    int x;
    Node *t;
    if(index < 0 || index > Length(p)) return -1;
    if(index == 0)
    {
       head=head->next;
       if(head)head->prev=NULL;
       
       x=p->data;
       free(p);
    }
    else
    {
        for(int i=0;i<index-1;i++)
        { 
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[5]={1,2,3,4,5};
    Create(A,5);
    Insert(head,10,3);
    Display(head);
    return 0;
}
