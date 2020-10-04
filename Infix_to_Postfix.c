#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// stack type 
struct stack 
{ 
    int top; 
    unsigned capacity; 
    char* arr; 
}; 

// stack creation
struct stack* create(unsigned capacity) 
{ 
    struct stack* stk = (struct stack*) malloc(sizeof(struct stack)); 
  
    if (!stk)  
        return NULL; 
  
    stk->top = -1; 
    stk->capacity = capacity;   
    stk->arr = (char*) malloc(stk->capacity * sizeof(char)); 
    if (!stk->arr)  
        return NULL;
  
    return stk;
} 

//check if the stack is empty or not.
int isEmpty(struct stack* stk) 
{ 
    return stk->top == -1 ; 
} 

//retrieve the topmost element from stack
char peek(struct stack* stk) 
{ 
    return stk->arr[stk->top]; 
} 

//pop the element from stack
char pop(struct stack* stk) 
{ 
    if (!isEmpty(stk)) 
        return stk->arr[stk->top--] ; 
    return '$';
} 

//push the element to stack
void push(struct stack* stk, char op) 
{ 
    stk->arr[++stk->top] = op; 
} 

//Check if the given character is operand 
int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

//return precedence of a given operator
int Prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 

//it is to convert a given infix expression to postfix expression
void infixToPostfix(char* exp) 
{ 
    int i, k; 
  
    // Create a stack of capacity equal to expression size  
    struct stack* stack = create(strlen(exp)); 
    if(!stack) // See if stack was created successfully  
        return; 
  
    for (i = 0, k = -1; exp[i]; ++i) 
    { 
        // If the scanned character is an operand, add it to output. 
        if (isOperand(exp[i])) 
            exp[++k] = exp[i]; 
          
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (exp[i] == '(') 
            push(stack, exp[i]); 
          
        // If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
        else if (exp[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                exp[++k] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return; // invalid expression              
            else
                pop(stack); 
        } 
        else // an operator is encountered 
        { 
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack))) 
                exp[++k] = pop(stack); 
            push(stack, exp[i]); 
        }
    } 
  
    // pop all the operators from the stack 
    while (!isEmpty(stack)) 
        exp[++k] = pop(stack ); 
  
    exp[++k] = '\0'; 
    printf("\nThe postfix exprssion is:%s", exp); 
} 

int main() 
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("The infix exprssion is:%s", exp);
    infixToPostfix(exp); 
    return 0; 
}
