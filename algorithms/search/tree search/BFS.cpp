#include <iostream>
#include<bits/stdc++.h>
#define MAX INT8_MAX

using namespace std;

/**
 * Breadth First Search (BFS) on tree
*/

int T[MAX], root, n;
bool visited[MAX];

void readData() {

    cout << "Number of nodes: ";
    cin >> n;

    cout << "Nodes: ";
    for(int i = 0; i < n; i ++) {
        cin>>T[i];

        // initialise visited list of nodes with false
        visited[i] = false;

        // find root
        if(i == T[i]) {
            root = i;
        }
    }
}

// get adjacent nodes of a node v
void getAdjacent(int v, vector<int>& adj) {
    for(int i = 0; i < n; i ++) {
        if(T[i] == v) {
            adj.push_back(i);
        }
    }
}

void BFS() {
    queue<int> q;
    visited[root] = true;

    q.push(root);

    while(!q.empty()) {
        
        int v = q.front();
        vector<int> adj;
        getAdjacent(v, adj);
        cout << v << " ";
        q.pop();

        for(auto i = adj.begin(); i != adj.end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main() {
    readData();
    BFS();
    cout << endl;
}
