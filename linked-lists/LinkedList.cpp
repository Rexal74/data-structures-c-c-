#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *head;

void create(int A[],int k)
{
  Node *t,*last;
  head=(Node *)malloc(sizeof(Node));
    head->data=A[0];
    head->next= NULL;
    last=head;
    for(int i=1;i<k;i++)
    {
        t=(Node *)malloc(sizeof(Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
        
    }
}

void display(Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int Count(Node *p)
{
    int count=0;
     while(p)
     {
        count++;
        p=p->next;
     }
    return count;

}

int Sum (Node *p)
{
    int sum=0, k=Count(p);
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int Maximum(Node *p)
{
    int max= -2147483648;
    while(p)
    {
        if(p->data > max) max=p->data;
        p=p->next;
    }
    return max;
}

int Minimum(Node *p)
{
    int min=214748;
    while(p)
    {
        if(p->data < min ) min=p->data;
        p=p->next;
    }
    return min;
}

Node * Search(Node *p, int key)
{
   while(p!=NULL)
   {
    if(p->data == key) return p;
    else
    {
        p=p->next;
    }
   }
   return NULL;
}

void Insert(Node *p ,int key ,int index)
{
    Node *t;
if(index<0 || index > Count(p))return;
else
{
    t=(Node *)malloc(sizeof(Node));
    t->data=key;
    t->next=NULL;
if(index==0)
{
  
    t->next=head;
    head=t;
}else
{
    for(int i=1;i<index;i++)
    {
    p=p->next;
    
          
    }
    t->next=p->next;
    p->next=t;
}
} 
}

void SortedInsert(Node *p ,int key)
{
    Node *t,*k;
    if(head == NULL){ 

        t=(Node *)malloc(sizeof(Node));
        t->data = key;
        t->next = NULL;
        head= t;
    }
    if(key < head->data){
      t=(Node *)malloc(sizeof(Node));
      t->data=key;
      t->next=p;
      head=t;   
    }else
    {

     while(p!=NULL && key>p->data)
     {
        k=p;
        p=p->next;
     }
     t=(Node *)malloc(sizeof(Node));
     t->data=key;
     t->next=p;
     k->next=t;
    }
}

int Delete(Node *p ,int index)
{
    Node *prev=NULL;
    int x=0;
    if(index < 1 || index > Count(p))
    {
      return -1;
    }
    if(index == 1)
    {
        x = p->data;
        head = p->next;
        free(p);
    }
    else
    {
     for(int i=0;i<index-1;i++)
     {
        prev = p;
        p = p->next;
     }
     x=p->data;
     prev->next=p->next;
     free(p);

    }
    return x;
}

void RemoveDup(Node *p)
{
    if(p == NULL) return;
    Node *t;
    t = p->next;
    while(t != NULL)
    {
        if(p->data == t->data)
        {
            p->next = t->next;
            free(t);
            t = p->next;  
         }else
         {
            p = p->next;
            t = p->next;
         }
    }
    }

void Reverse(Node *p)
{
        Node *q=NULL ,*r=NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void Reverse2(Node *q ,Node *p)
{
if(p)
{
Reverse2(p ,p->next);
p->next = q;
}
else{head = q;}

}

Node* Merge(Node *p ,Node *q)
{
    Node *third ,*last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    if(q) last->next = q;
    return third;
}
int main()
{
    int A[5]={2,2,9,9,16};
    create(A,5);
    Reverse(head);
    display(head);

    return 0;
}