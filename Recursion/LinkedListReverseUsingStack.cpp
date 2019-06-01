/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 1, 2019, 4:24 PM
 */

#include <iostream>
#include<stack>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
};
Node *head;

void insertEnd(int data)
{
    
    
    cout<<"inserted "<<data<<endl;
    Node *h= head;
    Node *newNode = new Node();
    newNode->data=data;
    if(head==NULL)
    {
        newNode->link = NULL;
        head=newNode;
        return;
    }
    while(h->link != NULL)
    {
        h=h->link;
    }
    
    newNode->link = NULL;
    h->link = newNode;
        
}
void printList(Node *h)
{
    while(h!=NULL)
    {
        cout<<h->data<<",";
        h=h->link;
    }
    cout<<endl;
}

void reverseList()
{
  if(head==NULL) return;
  stack <Node*> s;
  Node *h=head;
  while(h!=NULL)
  {
      s.push(h);
      h=h->link;
  }
  Node *temp;
  temp=s.top();
  head=s.top();
  s.pop();      //Removed the first element
  while(!s.empty())
  {
      temp->link=s.top();
      s.pop();
      temp=temp->link;
      
  }
  temp->link=NULL;
}
int main() 
{
  insertEnd(1);
 insertEnd(2);
  insertEnd(3);
  insertEnd(4);
  insertEnd(5);
  insertEnd(6);
  cout<<"Before reversal"<<endl;
  printList(head);
  reverseList();
  cout<<"After reversal"<<endl;
  printList(head);

    
}

