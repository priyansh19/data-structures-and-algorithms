/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 4, 2019, 12:25 PM
 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *front;
Node *rear;

void enqueue(int x) {
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    //Check if no element
    if (rear == NULL && front == NULL) {
        front = rear = newNode;
        return;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deque() {
    Node *temp = front;
    //check if there's no element
    if (rear == NULL) return;
    else if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

void printList() {
    Node *temp = front;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    deque();
    printList();
    enqueue(1);
    deque();
    printList();
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printList();
    deque();
    printList();
    enqueue(6);
    enqueue(7);
    enqueue(8);
    deque();
    printList();

}

