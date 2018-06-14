//Coded By: Anthony Lim arl150130
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "stack.h"


using namespace std;

//Prototype Functions
bool isOperand(char value);
bool isOperator(char value);
int precedence(char c);

//Main Function
int main()
{
    //Open Files
    ifstream input("exp.txt");
    ofstream output("values.txt");

    //Variables
    string value;
    string buffer= "";
    Stack stack1;
    float num = 0;
    while(getline(input, value))
    {
        string postfix= "";
        //Infix to Postfix
        for(int i = 0; i < value.length();i++) //Read Each Character of String
        {
            if(isOperand(value[i])) //If it is a number
            {
                while((isOperand(value[i]) || value[i] == '.') && (i< value.length())) //Keep reading in characters until not number or .
                {

                    buffer+=value[i];
                    i++;
                }
                i--;
                postfix+=buffer;
                postfix += " ";
                buffer = "";
            }
            else if(value[i] == '(') //If it is a (
            {
                stack1.push(value[i]);
            }
            else if(isOperator(value[i])) //If it is an Operator
            {
                while((!stack1.isEmpty()) && (precedence(value[i]) <= precedence(stack1.check()))) //Pop until lower precedence
                {
                    postfix+= stack1.check();
                    stack1.pop();
                }
                stack1.push(value[i]);
            }
            else if(value[i] == ')') //If it is a )
            {
                while((!stack1.isEmpty()) && (stack1.check() != '(')) //Pop until ( is at head of stack
                {
                    postfix+= stack1.check();
                    stack1.pop();
                }
                if(!stack1.isEmpty())
                stack1.pop();
            }
        }
        while(!stack1.isEmpty()) //Pop until stack is empty
        {
            postfix+= stack1.check();
            stack1.pop();
        }

        //Evaluate Postfix
        for(int i = 0; i < postfix.length();i++)
        {
            //cout << value[i];
            //cout << "STACK: ";
            //stack1.print() ;
            //cout << endl;
            if(isOperand(postfix[i]))
            {
                while((isOperand(postfix[i]) || postfix[i] == '.') && (i< postfix.length())) //Get whole floats before pushing
                {

                    buffer+=postfix[i];
                    i++;
                }
                i--;
                float num = atof(buffer.c_str());
                stack1.push(num);
                buffer = "";
            }
            else if(isOperator(postfix[i])) //If it is an operator, pop stack twice and evaluate
            {
               float op1 = stack1.checkf();
               stack1.pop();
               float op2 = stack1.checkf();
               stack1.pop();
               if(postfix[i]== '+')
               {
                   stack1.push(op1+op2);
               }
               else if(postfix[i]== '-')
               {
                   stack1.push(op2-op1);
               }
               else if(postfix[i]== '*')
               {
                   stack1.push(op1*op2);
               }
               else if(postfix[i]=='/')
               {
                   stack1.push(op2/op1);
               }
               else if(postfix[i] == '^')
               {
                   stack1.push(pow(op1,op2));
               }
            }
            else if(postfix[postfix.length()-1] == '\r') //Try to remove weird A<-----------------------------------------
            {
                postfix[postfix.length()-1] == '\n';
            }
        }
        //if(postfix[postfix.length()]== '\r')
          //  output<< postfix.substr(0,postfix.length()-1) << "\t";
        //else
        output << postfix << "\t";
        float num= stack1.checkf();
        output << fixed << setprecision(3) << num;
        output << endl;
    }
}

bool isOperand(char value) //If its an operand return true
{
    if(isdigit(value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOperator(char value) //if it is an operator return false
{
    if(value == '+' || value == '-' || value == '*' || value == '/' || value == '^')
    {
        return true;
    }
    else
        return false;
}

int precedence(char c) //Precedence for operators
{
    int prec = -1;
    switch(c)
    {
    case '(':
        prec = 1;
        break;
    case '+':
        prec = 2;
        break;
    case '-':
        prec = 2;
        break;
    case '*':
        prec = 3;
        break;
    case '/':
        prec = 3;
        break;
    case '^':
        prec = 4;
    }
    //cout << "prec is " << prec << endl;
    return prec;
}

