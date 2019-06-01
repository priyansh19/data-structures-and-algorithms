/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on May 28, 2019, 2:40 PM
 */

#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *link;
};

Node *top;

void insertStack(int x)
{
     Node *newNode=new Node();
    newNode->data=x;
    if(top==NULL)
    {
        newNode->link=NULL;
        top=newNode;
    }
    else
    {
    newNode->link=top;
    top=newNode; 
    }
    
}

void printStack(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<",";
        head=head->link;
    }
    cout<<endl;
}

void popStack()
{
    Node *temp;
    if(top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);
}
int main()
{
    insertStack(1);
    insertStack(2);
    insertStack(3);
    insertStack(4);
    insertStack(5); 
    insertStack(6); 
    insertStack(7);
    printStack(top);
        
    popStack(); 
    printStack(top);
        
}