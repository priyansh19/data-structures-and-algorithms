/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on May 29, 2019, 9:23 AM
 */

#include <iostream>
using namespace std;

class Node
{
public :
    int data;
    Node *prev;
    Node *next;
};

Node *head; //global pointer

Node* getNewNode(int x)
{
    Node *newNode = new Node();
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
    
}

void insertAtHead(int x)
{
    
    Node *newNode = getNewNode(x);
    if(head == NULL)
    {
        head=newNode;
    }
    else
    {
    head->prev=newNode;
    newNode->next=head;
    
    head=newNode;
  
    }
    
}

void printList()
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<",";
        temp=temp->next;
        
    }
}

void reversePrintList()
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<",";
        temp=temp->prev;
    }
}
int main() 
{
    
    insertAtHead(1);
    insertAtHead(2);
     insertAtHead(3);
    insertAtHead(4);
     insertAtHead(5);
    insertAtHead(6);
     insertAtHead(7);
    insertAtHead(8);
    
    cout<<"Forward printing"<<endl;
    printList();
    
    cout<<"Reverse Printing"<<endl;
    reversePrintList();
}

