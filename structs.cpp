#include <iostream>
using namespace std;
#define size 10

void push (struct stack *,int );
int pop (struct stack *);
void initial(struct stack *);
int isempty(struct stack *);
int isfull(struct stack *);
void reverse(struct stack*,struct stack* );
void printStack(struct stack*);

struct stack{
int top;
int item[size];
};
int main()
{	
    struct stack s1,s2;
    initial(&s1);
    initial(&s2);
    int x;

    srand(time(NULL));
     
	for (int i=0;i<size;i++)
	{
	    x=random() % 21;
	    push(&s1,x);
	}
	
    reverse(&s1,&s2);
    printStack(&s1);
    cout<<endl;
    printStack(&s2);

	return 0;
}
void initial(struct stack * s)
{
   s->top=-1;
}
int isempty(struct stack *s)
{
	if(s->top==-1)
	    return 1;
	else
		return 0;
}
int isfull(struct stack *s )
{
	if (s->top==size-1)
		return 1;
	else 
		return 0;
}
void push(struct stack *s,int n)
{
	if(isfull(s))
	cout<<"there is an over-flow"<<endl<<"the stack is full ";

		s->top++;
		s->item[s->top]=n;
}
int pop(struct stack *s )
{
	if (isempty(s))
	cout<<"there is an under flow"<<endl<<"the stack is empty";
	return s->item[(s->top)--];
	
}
void reverse(struct stack *s1,struct stack *s2 )
{   
    struct stack temp;
    initial(&temp);
    int x;

    while(!isempty(s1))
    {
        x=pop(s1);
        push(&temp,x);
        push(s2,x);
    }
    while(!isempty(&temp))
    {
        x=pop(&temp);
        push(s1,x);
    }
}
void printStack(struct stack *ps)
{
    struct stack temp;
    initial(&temp);
    int x;

    while(!isempty(ps))
    {
        x=pop(ps);
        push(&temp,x);
    }
    while(!isempty(&temp))
    {
        x=pop(&temp);
        push(ps,x);
        cout<<x<<" ";
    }
}