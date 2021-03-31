#include<bits/stdc++.h>
#define MAX INT8_MAX

using namespace std;

/**
 * Depth First Search (DFS) on tree
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

void DFS(int v) {

    vector<int> adj;
    getAdjacent(v, adj);
    visited[v] = true;

    cout << v << " ";
    
    for(auto i = adj.begin(); i != adj.end(); ++i) {
        if(!visited[*i]) {
            DFS(*i);
        }
    }
}

int main() {
    readData();
    DFS(root);
    cout << endl;
}