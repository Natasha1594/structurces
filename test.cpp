#include <iostream>
using namespace std;
#define STACKSIZE 3

struct 
{
    int top;
    int items[STACKSIZE];
}stack;

void printStack(struct stack *ps)
{
    int x;
    struct stack temp;
    initializeStack(&temp);
    while (!isStackEmpty(ps))
    {x = pop(ps); cout<<x<<endl; push(&temp,x);}
    while (!isStackEmpty(&temp))
    {x = pop(&temp); push(ps,x);}
}

void intializeStack(struct stack *ps)
{ps->top = -1;}

int isStackFull(struct stack *ps)
{
    if(ps->top == STACKSIZE-1) return 1;
    else return 0;
}
void push(struct stack *ps, int x)
{
    if(isStackFull(ps))
    {cout<<"Overflow: Stack is full\n";exit(1);}
    ps->top++;
    ps->items[ps->top]=x;
}
int isStackEmpty(struct stack *ps)
{
    if(ps->top == -1) return 1;
    else return 0;
}
int pop(struct stack *ps)
{
    if(isStackEmpty(ps)==1)
    {cout<<"Undderflow: Stack is empty\n"; exit(1);}
    return ps->items[(ps->top)--];
}



int main(void){
    struct stack x;
    int element;
    initializeStack (&x); 
    
    if isStackEmty (&x)
        cout<<"Satck is empty”<<"n;
    else
        cout<<"Stack is not empty";

    printStack (&x);
    system ("PAUSE");
    











    return 0;
}