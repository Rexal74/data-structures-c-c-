#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    Node *next;
}Node;

Node *top=NULL;

void push(char x)
{
    Node *t;
    t=(Node *)malloc(sizeof(Node));

    if(t==NULL)
    {
        printf("Stack is full");
    }
    else
    {

    t->data=x;
    t->next=top;
    top=t;
    }

}

char pop()
{
    Node *t;
    char x;
    if(top == NULL)
    {
        printf("Stack is empty\n");
          return '\0';
    }
    else
    {
      t=top;
      top=top->next;
      x=t->data;
      free(t);
    }
    return x;
}
void Display()
{
    Node *t;
    t=top;
    while(t)
    { 
        printf("%d ",t->data);
        t=t->next;
    } 
}

int isBalanced(const char *x)
{
    for(int i=0;x[i]!='\0';i++)
    {
        if(x[i] == '(') push(x[i]);
        else if(x[i] == ')')
        {
            if(top == NULL) return 0;
            pop();
             
        } 
    }
    if(top == NULL) 
    return 1;
    else 
    return 0;

}

int pre( char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

char * infixToPostfix(char *infix)
{
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+1)*sizeof(char));
    int i=0 ,j=0;
    while(infix[i] != '\0')
    {
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
          if(pre(infix[i]) > pre(top->data))
          {
            push(infix[i++]);
          }
          else
          {
            postfix[j++]=pop();
          }
        }
        else
        {
          postfix[j++]=infix[i++];
        }
    }
    while(top != NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *k=(char *)malloc(20*sizeof(char));
    k="a+b*c+d/e";
    push('.');
    printf("%s " ,infixToPostfix(k));
    return 0;
}