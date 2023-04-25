#include <iostream>
using namespace std;

void push (struct stack *,int );
char pop (struct stack *);
void initial(struct stack *);
int isempty(struct stack *);
int isfull(struct stack *);
void printstack(struct stack *);

struct stack{
int top;
char item[50];
};



void initial(struct stack *ps)
{
   ps->top=-1;
}
int isempty(struct stack *ps)
{
	if(ps->top==-1)
	    return 1;
	else
		return 0;
}
int isfull(struct stack *ps )
{
	if (ps->top == 49)
		return 1;
	else 
		return 0;
}
void push(struct stack *ps,char x)
{
	if(isfull(ps))
    {
        cout<<"Overflow: Stack is full";
        exit(1);
    }
	
		ps->top++;
		ps->item[ps->top]=x;
}
char pop(struct stack *ps )
{
	if (isempty(ps)==1){
        cout<<"there is an under flow"<<endl<<"the stack is empty";
	    exit(1);
    }
    return ps->item[(ps->top)--];
	
	
}

void printstack(struct stack *ps)
{
    char x;
    struct stack temp;
    initial(&temp);

    while(!isempty(ps))
    {
        x = pop(ps);
        cout<<x;
        push(&temp,x);
    }

    while(!isempty(&temp))
    {
        x = pop(&temp);
        push(ps,x);
    }
    cout<<"\n\n";

}

int matching(char symb, char x)

{
    if ( (x=='(' && symb==')') || (x=='[' && symb==']') || (x=='{' && symb=='}') )
    
        return 1;
    else
        return 0;
}


int main(void)
{
    int valid=1, i=0;
    char eq[20],symb,x;
    struct stack s;
    initial(&s);


    cout<<"Please enter the equation:";
    cin>>eq;

    while(eq[i]!='\0')
    {

        symb = eq[i];
        if (symb=='(' || symb=='[' || symb=='{')
        {
            push(&s,symb);
        }
        if (symb==')' || symb==']' || symb=='}')
        {
           if (isempty(&s))
            valid = 0;

            else{
                x = pop(&s);
                if (matching(symb,x)==0)
                    valid = 0;
                
            }
           
        }
        cout<<"Stack after symb "<<symb<<" is as follows: "<<endl;
        printstack(&s);
        i++;
        
    }

    if (!isempty(&s))
    valid = 0;
    if (valid)
    cout<<"\n\n string is valid";
    else
    cout<<"\n\n string is no valid(invalid)\n\n";

    system ("PAUSE");
    

    return 0;

}



