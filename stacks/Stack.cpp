#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int size;
    int top;
    int *S;
}Stack;

void Create(Stack *st)
{
printf("Please enter the sizse");
    scanf("%d" ,st->size);   
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}
void Display(Stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        printf("%d\n",st.S[i]);
    }
}

void Push(Stack *st,int x)
{
    if(st->top==st->size-1)
    printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int Pop(Stack *st,int pos)
{
    int x=-1;
    if(st->top=-1)
    printf("Stack Undeflow \n");
    else
    {
        x=st->S[st->top];
        st->top--;
    }
    return x;
}
int peek(Stack st,int index)
{
int x=-1;
if(st.top-index+1<0)
printf("Invalid Index \n");
else x=st.S[st.top-index+1];
return x;
}

int isEmpty(Stack st)
{
    if(st.top==-1) return -1;
return 1;
}
int isFull(Stack st)
{
    if(st.top==st.size-1) return -1;
    return 1;
}

int main() 
{
    Stack stack;
    
    return 0;
}