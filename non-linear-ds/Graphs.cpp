/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 14, 2019, 1:40 PM
 */

#include <bits/stdc++.h>
using namespace std;

const int v = 7;
vector<int> graph[v];

void detectCycle(int s) {
    //s is the source
    stack<int> q;
    int a[v];
    //Visited array
    for (int i = 0; i < v; i++) {
        a[i] = -1;
    }
    q.push(s);
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        if (a[cur] < 0) {
            //cout<<cur<<" ";
            a[cur]++;
            for (int x : graph[cur]) {
                if (a[x] == -1) q.push(x);
            }
        } else {
            cout << "cycle present";
            return;
        }



    }
    cout << "Cycle not present !";
}

void BfsOrder(int s) {
    cout << "BFS traversal " << endl;
    //s is the source
    queue<int> q;
    int a[v];
    //Visited array
    for (int i = 0; i < v; i++) {
        a[i] = -1;
    }
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (a[cur] == -1) {
            cout << cur << " ";
            a[cur] = 0;
            for (int x : graph[cur]) {
                if (a[x] == -1) q.push(x);
            }
        }



    }

    cout << endl;
}

void DfsOrder(int s) {
    cout << "DFS traversal " << endl;
    //s is the source
    stack<int> q;
    int a[v];
    //Visited array
    for (int i = 0; i < v; i++) {
        a[i] = -1;
    }
    q.push(s);
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        if (a[cur] == -1) {
            cout << cur << " ";
            a[cur] = 0;
            for (int x : graph[cur]) {
                if (a[x] == -1) q.push(x);
            }
        }



    }

    cout << endl;
}

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph() {
    for (int x = 0; x < v; x++) {
        cout << "Adjacency list of " << x << ":" << endl;
        for (auto u : graph[x]) {
            cout << u << " ";
        }
        cout << endl;
    }
}

int main() {
    /*addEdge(0,1); 
    addEdge(0,2); 
    addEdge(1,3); 
    addEdge(2,4); 
    addEdge(3,5); 
    addEdge(4,5); 
    addEdge(3,4); 
    addEdge(4,1); */
    /* addEdge(0, 1); 
     addEdge(0, 2); 
     addEdge(1, 2); 
     addEdge(2, 0); 
     addEdge(2, 3); 
     addEdge(3, 3); */
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(6, 5);
    printGraph();
    BfsOrder(0);
    DfsOrder(0);
    detectCycle(0);
}

