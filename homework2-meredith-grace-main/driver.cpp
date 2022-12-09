//Grace Meredith
//cs302 Homework 2
//23 Feb 2021

#include <iostream>
#include <string>
using namespace std;

#include "linkedStack.h"

int scanNumber(char ch);
bool isOperator(char ch);
bool isOperand(char ch);
int operation(int num, int num2, char op);
int postfixing(string expression);

int main(){
    string expression;
    cout << endl << "Hello! Please enter your expression: ";
    cin >> expression; 
    cout << endl << "The result is: " << postfixing(expression) << endl;

    return 0;
}

int scanNumber(char ch){
    int value;
    value = ch;

    return value;; //convert character to float 
}

bool isOperator(char ch){
    bool Operator = (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    return Operator; 
}

bool isOperand(char ch){
    bool Operand = (ch >= '0' && ch <= '9');
    return Operand; 
}

int operation(int num, int num2, char op){
    if(op == '+'){
        return num + num2;
    }
    else if(op == '-'){
        return num - num2;
    }
    else if(op == '*'){
        return num * num2;
    }
    else if(op == '/'){
        return num / num2;
    }
    else{
        throw "error";
    }
}

int postfixing(string expression){
    int a, b;
    char o;
    LinkedStack<int> stk;
    LinkedStack<char> stk2;
    string::iterator i;

    for(i = expression.begin(); i != expression.end(); i++){
        if(isOperator(*i)){
            a = stk.peek();
            stk.pop();
            b = stk.peek();
            stk.pop();
            if(*i == '*' || *i == '/'){
                 stk.push(operation(a,b, *i));
            }
            else{
                o = *i;
                stk2.push(o);
;            }
        }
        else if(isOperand(*i)){
            stk.push(scanNumber(*i));
        }
    }
    while(!stk2.isEmpty()){
        char c = stk2.peek();
        stk2.pop();
        a = stk.peek();
        stk.pop();
        b = stk.peek();
        stk.pop();
        stk.push(operation(a, b, c));
    }
    return stk.peek();
}