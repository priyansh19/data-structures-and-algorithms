/*
 Priority queues are a type of container adapters, specifically designed 
 * such that the first element of the queue is the greatest of all elements in the 
 * queue and elements are in non decreasing order
 * (hence we can see that each element of the queue has a priority{fixed order}).
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 9, 2019, 7:21 PM
 */

#include <iostream>
#include<queue>
using namespace std;
void print( priority_queue<int> pq)
{
     priority_queue<int> p = pq;
     while(!p.empty())
     {
         cout<<" "<<p.top();
         p.pop();
     }
     cout<<endl;
}
int main() {

    priority_queue<int> pq;
    pq.push(5);
    pq.push(7);
    pq.push(10);
    pq.push(19);
    pq.push(15);
    print(pq);
    
    cout<<"The size of priority queue is "<<pq.size()<<endl;
     cout<<"The top element of priority queue is "<<pq.top()<<endl;
     pq.pop();
     print(pq);
}

