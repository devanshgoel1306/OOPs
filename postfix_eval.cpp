// Postfix evaluation
// For Postfix evaluation, we use stack.

// Steps to follow:
// 1. Take an empty stack 
// 2.Traverse the expression from left to right
// 3.If character is operand then push onto the stack.
// 4.If it's an operator then pop 2 values and evaluate the expression operand2 operator operand1.
// Push the result onto the stack.
// 5. Repeat steps from 3-4 till whole expression is traversed.
// 6. Stack will now contain only one element which is the required value.

#include <iostream>
using namespace std;

class Stack{
    private:
    int arr[10];
    int top;
    
    public:
    //creating an empty stack
    Stack(){
        top= -1;
    }
    
    //check if stack is empty
    bool is_empty()
    {
        return top==-1;
    }
    
    //check if stack is full
    bool is_full()
    {
        return top==10;
    }
    
    void push(int value){
        //if stack is not overflow
        if(!is_full())
        arr[++top]= value;
    }
    
    int pop(){
        //if stack is not underflow
        if(is_empty()){
            cout<<"Stack is empty.";
            return -1;
        }
            
        return arr[top--];
    }
};

int evaluate(string expr)
{
    //create an object of class stack
    //default constructor will be called
    Stack s;
    
    //traversing the expression
    int i=0;
    while(expr[i]!='\0'){
        //if not an operator then push onto the stack
        if(expr[i]!='+' && expr[i]!='-' && expr[i]!='*' && expr[i]!='/' )
        {
            s.push(expr[i]-48);
            //cout<<expr[i]-48<<" ";
        }
        //if operator is encountered
        else{
            //pop twice
            int op1= s.pop(), op2= s.pop();
            
            //perform the operation
            int eval= 0;
            switch(expr[i]){
                case '+': eval= op2+op1; break;
                case '-': eval= op2-op1; break;
                case '*': eval= op2*op1; break;
                case '/': eval= op2/op1; break;
            }
            
            //push result to stack
            s.push(eval);
        }
        i++;
    }
    return s.pop();
}

int main()
{
    //input postfix expression
    string expr;
    cin>>expr;
    
    cout<<evaluate(expr);

    return 0;
}

