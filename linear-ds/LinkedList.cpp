
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
void printList(Node *h)
{
    while(h!=NULL)
    {
        cout<<h->data<<",";
        h=h->link;
    }
    cout<<endl;
}
void insertHead(Node **head)
{
    Node *h = *head;
    Node *newNode = new Node();
    newNode->data=0;
    newNode->link = h;
    *head = newNode;
}

void insertAfter(Node **head)
{
    Node *h = *head;
    Node *newNode = new Node();
    newNode->data=8;
    while(h!=NULL)
    {
        if(h->data==2)
        {
            
            newNode->link = h->link;
            h->link = newNode;
            break;
        }
        
        h=h->link;
    }
}

void insertEnd(Node **head,int data)
{
    Node *h= *head;
    Node *newNode = new Node();
    newNode->data=data;
    
    while(h->link != NULL)
    {
        h=h->link;
    }
    
    newNode->link = NULL;
    h->link = newNode;
        
}

void deleteNodePos(Node **head,int pos)
{
    Node *h=*head;
    int count=0;
    //Stopping at the previous node
    while(count!= (pos-1))
    {
        h=h->link;
        count++;
    }
   //TODO - freeing up the memory using delete or free operator
    h->link = h->link->link;
    
}
void deleteNodeFirst(Node **head)
{
    Node *h= *head;
 
    //Getting the previous node
    h= *head;
    while(h->link->data != 2)
    {
        h=h->link;
    }
   //TODO - free up memory allocation using free or delete operator
   
   
    h->link = h->link->link;
    
}
void deleteList(Node **head)
{
//    Iterate through the linked list and delete all the nodes one by one. 
    
    Node *h = *head;
    Node *next;
    while(h!=NULL)
    {
       next = h->link;
       free(h);
       h=next;
    }
    *head=NULL;
}
    
void reverseIterative(Node **head)
{
    Node *current,*prev,*next;
    //prev - To keep track of the previous node
    current = *head;
    prev = NULL;
    while(current!=NULL)
    {
        next=current->link;
        current->link= prev;
        prev=current;
        current=next;
        }
    *head=prev;
}

Node* reverseRecursive(Node *node)
{
   
    if(node==NULL)
    {
        return NULL ;
    }
    if(node->link == NULL)
    {
        return node ;
    }
    
    Node *node1 = reverseRecursive(node->link);
    cout<<node1->data<<endl;
    node->link->link = node;
    node->link=NULL;
    return node1;
    
}
int main() 
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    
    
    head->data =1;
    head->link= second;
    
    second->data=2;
    second->link=third;
    
    third->data=3;
    third->link=NULL;
    
    printList(head);
    
    //Inserting a node at the head of the list
    cout<<"Inserting 0 at the head of the list"<<endl;
    insertHead(&head);
    printList(head);
    
    //Inserting a node after a given node - say after 2
    cout<<"Inserting 8 after 2"<<endl;
    insertAfter(&head);
    printList(head);
    
    //Insert a node at the end
    cout<<"Inserting 10 at the end of the list"<<endl;
    insertEnd(&head,10);
    printList(head);
    
    //Deleting the first occurrence of a node - let us say delete 2
    cout<<"Deleting the first occurrence of node 2"<<endl;
    deleteNodeFirst(&head);
    printList(head);
    
    //Deleting at a specific position from the linked List
    //position starts at position 0 in L.L
    cout<<"Deleting node at position 2"<<endl;
    deleteNodePos(&head,2);
    printList(head);
    
    cout<<"Deleting the entire linked List"<<endl;
    deleteList(&head);
    printList(head);
    
    cout<<"Inserting more values"<<endl;
    //we've got to assign head again since it was freed up
    head = new Node();
    head->data =1;
    head->link= NULL;
    insertEnd(&head,0);
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);
    printList(head);
    
    //Reversing a linked list - iterative approach
    cout<<"Reversing the list"<<endl;
    reverseIterative(&head);
    printList(head);
    
      //Reversing a linked list - recursive approach
    cout<<"Reversing the list recursively"<<endl;
   head = reverseRecursive(head);
    printList(head);
}

