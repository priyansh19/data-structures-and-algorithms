/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 10, 2019, 8:14 PM
 */

// C++ program to insert a node in AVL tree  
#include<iostream> 
using namespace std;

// An AVL tree node  

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *root) {
    if (root == NULL) 
        return 0;
    return root->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* getNewNode(int x) {
    Node* newNode = new Node();
    newNode->key = x;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getBalance(Node *root) {
    if (root == NULL) return 0;
    return (height(root->left) - height(root->right));
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    //Perform rotation
    x->right = y;
    y->left = t;

    //Update heights 
    y->height = max(height(y->left),
            height(y->right)) + 1;
    x->height = max(height(x->left),
            height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *t = y->left;

    //ROtate
    y->left = x;
    x->right = t;

    //Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;

}

Node* insert(Node* head, int a) {
    if (head == NULL)
        return (getNewNode(a));

    else if (a < head->key)
        head->left = insert(head->left, a);

    else if (a > head->key)
        head->right = insert(head->right, a);

        //equal values not allowed in BST
    else
        return head;

    //2. Updating the height of the ancestor
    head->height = max((height(head->left)), (height(head->right))) + 1;

    //3. Get the balance factor
    int balance = getBalance(head);

    //4. Check for any unbalances
    //Left left case
    if (balance > 1 && a < head->left->key) {
        //Right rotate;
        return rightRotate(head);
    }        //right right case
    else if (balance<-1 && a > head->right->key) {
        //Left rotate
        return leftRotate(head);
    }        //left right case
    else if (balance > 1 && a > head->left->key) {
        //Left right rotate
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }        //right left case
    else if (balance <-1 && a < head->right->key) {
        //Right left rotate
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }

    //Return the unchanged node
    return head;
}
int findMin(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->key;
}

Node* deleteNode(Node *root,int x)
{
    // STep 1. Insert normally as in BST
    if(root==NULL) return NULL;
    else if(root->key < x)
    {
        root->right = deleteNode(root->right,x);
    }
    else if(root->key >x)
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
        root->key=min;
        root->right=deleteNode(root->right,min);
    }
}
      // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
    root->height = max((height(root->left)), (height(root->right))) + 1;

    //3. Get the balance factor
    int balance = getBalance(root);

    //4. Check for any unbalances
    //Left left case
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
    
}
void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;

    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  


    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
     */
    cout << "preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
root = deleteNode(root, 10);  
  
    /* The AVL Tree after deletion of 10  
            1  
        / \  
        0 9  
        / / \  
    -1 5     11  
        / \  
        2 6  
    */
  
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";  
    preOrder(root);  
  
    return 0;  
}