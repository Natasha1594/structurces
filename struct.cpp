#include <iostream>
using namespace std;
#define STACKSIZE 4



//Declaring the structure stack
struct stack{
    int top;
    int items[STACKSIZE];
};

void initializeStack(struct stack *ps){
    ps->top = - 1;
}
 
 //checks if the stack is full
int isStackFull(struct stack *ps){
    if(ps->top == STACKSIZE-1){
        return 1;
    }else{
        return 0;
    } 
}
 //pushes data to the stack
void push(struct stack *ps, int x){
    if(isStackFull(ps)){
        cout<<"Overflow: Stack is full\n";
    
        exit(1);
    }
        ps->top++;
        ps->items[ps->top]=x;
    
}
  //checks if the stack is empty
int isStackEmpty(struct stack *ps){
    if(ps->top == -1){
        return 1;
    }else{
        return 0;
    }
}

//removes/pops data from the stack
int pop(struct stack *ps){
    if(isStackEmpty(ps)==1){
        cout<<"Underflow: stack is empty\n";
        exit(1);
    }
    return ps->items[(ps->top)--];
}

//outputs the contents of the stack
void printStack(struct stack *ps){
    int x;
    struct stack temp;
    initializeStack(&temp);

    while(!isStackEmpty(ps)){
        x = pop(ps);
        cout<<x<<endl;
        push(&temp,x);
    }

    while(!isStackEmpty(&temp)){
        x = pop(&temp);
        push(ps,x);
    }
}


//it averages from two different stacks and places the data in the third stack
void stackAvg(struct stack *ps, struct stack *ps1, struct stack *ps2){
    int x, x1;
    struct stack temp,temp1;
    initializeStack(&temp);
    initializeStack(&temp1);

    while(!isStackEmpty(ps)){
        x = pop(ps);
        push(&temp,x);
    }

    while(!isStackEmpty(ps1)){
        x1 = pop(ps1);
        push(&temp1,x1);
    }

    //!-not
    while(!isStackEmpty(&temp)&&!isStackEmpty(&temp1)){
        x1 = (pop(&temp)+pop(&temp1))/2;
        push(ps2,x1);
    }
}

int main (){
    struct stack x,y,z;
    initializeStack(&x);
    initializeStack(&y);
    initializeStack(&z);
    push(&x, 20);
    push(&x, 5);
    push(&x, 15);
    push(&x, 10);
    push(&y, 5);
    push(&y, 2);
    push(&y, 7);
    push(&y, 6);
    
    cout<<"This is stack x: "<<endl;
    printStack(&x);
    
    cout<<"This is stack y: "<<endl;
    printStack(&y);
    stackAvg(&x, &y, &z);

    cout<<"This is stack z: "<<endl;
    printStack(&z);

return 0;
}


