/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 5, 2019, 6:12 AM
 */

#include <iostream>
#include<queue>
#include<climits>
using namespace std;
class Node 
{
public :
    int data;
    Node *left;
    Node *right;
};

Node* getNewNode(int a)
{
    Node *temp = new Node();
    temp->data=a;
    temp->left=NULL;
    temp->right = NULL;
    return temp;
}
Node* insertNode(Node *head,int x)
{
    Node *newNode = getNewNode(x);
   
    if(head == NULL)
    {
        head = newNode;
    }
    
    else if (x<= head->data)
    {
       head->left = insertNode(head->left,x);
    }
    else
    {
        head->right = insertNode(head->right,x);
    }
    return head;
}

bool searchNode(Node *root,int x)
{
    if(root == NULL) return false;
    if(root->data == x) return true;
    else if(x <= root->data)
    {
        searchNode(root->left, x);
    }
    else
    {
        searchNode(root->right, x);
    }
}

int findMin(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
Node* findMinNode(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
void findMax(Node *root)
{
    Node *temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    cout<<endl<<"Maximum element is "<<temp->data<<endl;
}
int max(int a,int b)
{
    if(a>b) return a;
    else if(a==b) return a;
    else return b;
}
int findHeight(Node *root)
{
    if(root==NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return max(leftHeight,rightHeight)+1;
}
void LevelOrderTraversal(Node *root)
{
    cout<<"Level order traversal"<<endl;
    Node *temp=root;
    if(temp==NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(temp);
    while(!q.empty())
    {
        Node *cur = q.front();
        cout<<cur->data<<",";
        if(cur->left!=NULL) q.push(cur->left);
        if(cur->right!=NULL) q.push(cur->right);
        q.pop();
    }
}

void PreOrder(Node *root)
{
    if(root==NULL) return;
    cout<<root->data<<",";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node *root)
{
    if(root==NULL) return;
    InOrder(root->left);
    cout<<root->data<<",";
    InOrder(root->right);
}
void PostOrder(Node *root)
{
    
    if(root==NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<",";
}
bool isBSTUtil(Node *head,int min,int max)
{
    if(head==NULL ) return true;
    
    if(head->data > min &&
            head->data < max &&
            isBSTUtil(head->left,min,head->data) &&
            isBSTUtil(head->right,head->data,max))
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool isBST(Node *root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
}
Node* deleteNode(Node *root,int x)
{
    if(root==NULL) return NULL;
    else if(root->data < x)
    {
        root->right = deleteNode(root->right,x);
    }
    else if(root->data >x)
    {
        root->left = deleteNode(root->left,x);
    }
    else {
    if(root->left==NULL && root->right == NULL)
    {
        delete root;
        root=NULL;
    }
    else if(root->left==NULL)
    {
        Node *temp=root;
        root=root->right;
        delete temp;
    }
    else if(root->right==NULL)
    {
        Node *temp=root;
        root=root->left;
        delete temp;
    }
    else{
        int min=findMin(root->right);
        root->data=min;
        root->right=deleteNode(root->right,min);
    }
}
    return root;
}
Node* findNode(Node *head,int data)
{
    cout<<"Finding Node "<<data<<endl;
    Node *temp=head;
    if(temp==NULL)
    {
        return NULL;
    }
    queue<Node *> q;
    q.push(temp);
    while(!q.empty())
    {
        Node *cur = q.front();
        if(cur->data == data) 
        {
            return cur;
        }
        else
        {
        cout<<cur->data<<",";
        if(cur->left!=NULL) q.push(cur->left);
        if(cur->right!=NULL) q.push(cur->right);
        q.pop();  
        }
       
    }
}
Node* getSuccessor(Node *root,int a)
{
    Node *current = findNode(root,a);
    if(current == NULL) return NULL;
    //Case 1 : When there is a right sub-tree
    if(current->right != NULL)
    {
        cout<<"Entered";
        return findMinNode(current->right);
    }
    
    //Case 2 : When there is no right sub-tree
    else
    {
        Node *successor=NULL;
        Node *ancestor=root;
        while(ancestor!=current)
        {
            if(current->data < ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
            {
                 ancestor=ancestor->right;
            }
        }
        return successor;
    }
    
}
int main() {
    Node *head=NULL;
//Insert in BST
 /* Let us create following BST 
               50 
            /      \ 
          30        70 
         / \        /  \ 
       20   40      60   80 
               \         /
               45       75    */
    
    head = insertNode(head, 50); 
    head = insertNode(head, 30); 
    head = insertNode(head, 20); 
    head = insertNode(head, 40); 
    head = insertNode(head, 45);
    head = insertNode(head, 70); 
    head = insertNode(head, 60); 
    head = insertNode(head, 80); 
    head = insertNode(head, 75); 
    //Search in BST
 
    cout<<"Search for 150 :";
    cout<<searchNode(head,150);
    cout<<"Search for 40 :";
    cout<<searchNode(head,40);
    cout<<endl<<"InOrder "<<endl;
    InOrder(head);
    cout<<endl<<"PostOrder "<<endl;
    PostOrder(head);
    cout<<endl<<"PreOrder "<<endl;
    PreOrder(head);
    //Max and min element in BST
    cout<<"Minimum number :"<<findMin(head)<<endl;
    findMax(head);
    //Find height of binary tree
    cout<<"Height of tree is "<<findHeight(head)<<endl;
    //Level order traversal or breadth first search
    LevelOrderTraversal(head);
    cout<<endl<<"Is tree a BST ? "<<isBST(head);
    //Delete a node from BST
    //Let's delete 70
    cout<<"After deleting 70"<<endl;
    head = deleteNode(head,70);
    cout<<endl<<"InOrder "<<endl;
    LevelOrderTraversal(head);
    //Predicting InOrder Successor
    Node *successor = getSuccessor(head,20);
    cout<<endl;
    InOrder(head);
    if(successor!=NULL)
    {
       cout<<endl<<"Successor of 20 is "<<successor ->data; 
    }
    else
    {
        cout<<endl<<"No successor exists"<<endl;
    }
    
   
}

