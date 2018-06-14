//Coded By: Anthony Lim arl150130
#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

//ofstream output("values.txt");
void Stack::print() //Print Char Head
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->getOperate();
        temp = temp->getNext();
    }
}

void Stack::printf() //Print float Head
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->getOperand() << " ";
        temp = temp->getNext();
    }
    cout<< endl;
}

void Stack::push(float number) //Push Float
{
    if(head == nullptr)
    {
        head = new node;
        head->setOperand(number);
        head->setNext(nullptr);
    }
    else {
        node* temp;
        temp = new node;
        temp->setOperand(number);
        //cout << "SETTING Next of " << temp->getOperate() << " to " << head->getOperate() << endl;
        temp->setNext(head);
        head = temp;
    }
}

void Stack::push(char c) //Push Char
{
    if(head == nullptr)
    {
        head = new node;
        head->setOperate(c);
        head->setNext(nullptr);
    }
    else {
        node* temp;
        temp = new node;
        temp->setOperate(c);
        //cout << "SETTING Next of " << temp->getOperate() << " to " << head->getOperate() << endl;
        temp->setNext(head);
        head = temp;
    }
}

void Stack::pop() //Pop node
{
    node*temp;
    if(head == nullptr)
    {
       // cout << "Stack is Empty! Nothing to Pop!";
    }
    else
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }
}


char Stack::check() //Look at Head and Return Char
{
    if(head == nullptr)
    {
        return '\0';
    }
    char c2 = head->getOperate();
    //cout << "Head is " << c2 << endl;
    return c2;
}

float Stack::checkf() //Return float at head
{
    if(head == nullptr)
    {
        return '\0';
    }
    float num = head->getOperand();
    return num;
}

bool Stack::isEmpty() //Check is list is empty
{
    if (head == nullptr)
        return true;
    else
        return false;

}
