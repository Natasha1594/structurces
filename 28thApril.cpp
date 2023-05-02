#include <iostream>
#include  <stdlib.h>
#include  <ctype.h>
#include  <string.h>

#define SIZE 100
using namespace std;

char stack[SIZE];
int top = -1;


void push(char item)
{
    if(top >= SIZE - 1){
        cout<<("\nStack overflow.");
    }
    else{
        top = top + 1;
        stack [top] = item;
    }
}

char pop()
{
    char item;
    if (top < 0)
    {
       cout<<("stack under flow: invalid infix expression");
       getchar();


       exit(1);
    }
    else{
        item = stack[top];
        top = top - 1;
        return(item);
    }
}

int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-'){
        return 1;
    }
    else{
        return 0;
    }
} 

int precedence(char symbol)
{
    if (symbol == '^') /* exponent operator, highest precedence */
    {
        return(3);
    }
    else if(symbol == '*' || symbol == '/'){
        return(2);
    }
    else if (symbol == '+' || symbol =='-')/*lowest precedence*/
    {
        return(1);
    }
    else{
        return(0);
    }
}

void InfixToPostifx(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;
    push('('); /*push '(' onto stack*/
    strcat(infix_exp, ")"); /* add ')' to infix expression*/
    i=0;
    j=0;
    item = infix_exp[i];

    while(item != '\0') /* run loop till end of infix expression*/
    {
        if (item == '('){
            push(item);
        }
        else if (isdigit(item) || isalpha(item)){
            postfix_exp[j] = item; /* add operand symbol to postfix exp*/
            j++;
           
        }
        else if(is_operator(item) == 1)/* mean symbol is operator*/
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item)){
                postfix_exp[j] = x; /* so pop all higher precedence operator and */
                j++;
                x = pop(); /* add them to postfix expression*/
            }
            push(x);
            push(item); /* push current operator symbol onto stack*/
        }
        else if (item == ')') /* if current symbol is ')' then*/
        {
            x = pop();/* pop and keep popping until*/
            while(x != '(')/* '(' encountered*/
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else{/* if current symbol is neither operand not '(' nor ')' and nor operator*/
        
        cout<<("\nInvalid infix Expression.\n"); /*the illegal symbol*/
        
        exit(1);
        }
        postfix_exp[j]= '\0'; /* add sentinel else puts() function, will print entire postix{} array upto SIZE*/

    }
}

int main()
{
    char infix[SIZE], postfix[SIZE];

    cout<<("\nEnter infix expression:");
    cin>>(infix);

    InfixToPostifx(infix, postfix);
    cout<<("Postfix Expression: ");
    cout<<(postfix);

    return 0;
}