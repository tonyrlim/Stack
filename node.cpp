//Coded By: Anthony Lim arl150130
#include "node.h"

node::node() //Default
{
    next = nullptr;
}

bool node::hasNext() //Check if has next
{
    if(next != nullptr)
        return true;
    else
        return false;
}

node* node::getNext() //Return next
{
    return next;
}


float node::getOperand() //Get float
{
    //cout<< sizeof(operand) << " ";
    return operand;
}

char node::getOperate() //Get Char
{
    return operate;
}

void node::setNext(node* newNext) //Set Next to new
{
    next = newNext;
}

void node::setOperate(char oper) //Set Operator
{
    operate = oper;
}

void node::setOperand(float val) //Set Operand
{
    operand = val;
}
