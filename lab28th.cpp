#include <iostream>
#include <random>
#include <ctime>
using namespace std;
void push (struct stack *,int );
int pop (struct stack *);
void initial(struct stack *);
int isempty(struct stack *);
int isfull(struct stack *);
void reverse(int [],int );
#define size 10
struct stack{
int top;
int item[size];
};
int main()
{	srand(time(NULL));
     
	int array[10];	
		cout<<"the array before "<<endl;
	for (int i=0;i<size;i++)
	{
	array[i]=random() % 21;
	cout<<array[i]<<"\t";

	}
	
    reverse( array, 10);

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
void reverse(int array[],int n)
{   struct stack s;
    initial(&s);
    for (int i=0;i<size;i++)
    {
        push(&s,array[i]);
    }
    cout<<endl<<"array after changing"<<endl;
    for (int j=0;j<size;j++)
    {
       cout<<pop(&s)<<"\t";
        
    }
}