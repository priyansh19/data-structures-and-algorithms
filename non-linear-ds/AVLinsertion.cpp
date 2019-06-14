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

    return 0;
}