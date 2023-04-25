#include <iostream>
using namespace std;
#define STACKSIZE 3


struct stack
   {
        int items[50];
        int top;
    };



//Intializing the stack
void intitStack(struct stack *ps){
    ps->top = -1;
}


//to find thr top of thr stack
int top_of_the_stack(struct stack *ps){
    return ps->items[ps->top];
}

void printStack(struct stack *ps){
    int x;
    struct stack temp;
    intializeStack(&temp){
        cout<<"stack elements are:"<<"\n";
    }
        
    while (isStackEmpty(ps))
    {
       x='pop'(ps);
       cout<<x<<endl;
       push(stack &temp,'x');
    }
        cout<<"stack elements in reverse:"\n";
    
    
}

//checking if the stack is empty
int isStackEmpty(struct stack *ps){
    if(ps->top == -1){
        
        return 1;
    }
        
    else
        return 0; //stack is not empty
}
    
void push( struct stack *ps, int x){
    // if(isStackEmpty(ps)){
    //    cout<<"Overflow:Stack is full"<<endl;
    //    exit (1);
    // }
        
    ps->top++;
    ps->items[ps->top]=x;
    cout<<x;
}





int main(void){

    struct stack s;
    int element;
    intitStack(&s);
    if (isStackEmpty(&s)){
        push(&s,6);
        push(&s,7);
        push(&s,9);
    }
        
        
    else
        cout<<"Stack is not empty";
    
    
    
    cout<<"Top of the stack is"<<top_of_the_stack(&s)<<endl;
    return 0;
}











