#include<bits/stdc++.h> 
#define MAX INT8_MAX

using namespace std;

/**
 * Iterative Deepening Depth First Search (IDDFS) on tree
*/

int T[MAX], root, n, goalNode;

void readData() {

    cout << "Number of nodes: ";
    cin >> n;

    cout << "Goal node: ";
    cin>>goalNode;

    cout << "Nodes: ";
    for(int i = 0; i < n; i ++) {
        cin>>T[i];

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

// Depth Limited Search (DLS) and helper function for IDDFS
pair<int, bool> DLS(int node, int depth) {

    if(depth == 0) {

        if(node == goalNode) {
            return std::make_pair(node, true);
        } else {
            return std::make_pair(NULL, true);
        }

    } else if (depth > 0) {

        bool remaining = false;
        vector<int> adj;

        getAdjacent(node, adj);
    
        for(auto i = adj.begin(); i != adj.end(); ++i) {

            pair<int, bool> p= DLS(*i, depth - 1);

            if(p.first != NULL) {
                p.second = true;
                return p;
            }

            if(p.second) {
                remaining = true;
            }
        }

        return std::make_pair(NULL, remaining);
    }
}

// Iterative Deepening Depth First Search
int IDDFS() {

    for(int depth = 0; depth < MAX; depth ++) {

        pair<int, bool> p = DLS(root, depth);

        if(p.first != NULL) {
            return p.first;
        } else if (!p.second) {
            return NULL;
        }
    }
}

int main() {

    readData();

    cout << "Status: ";
    cout << (goalNode == IDDFS());
    
    cout << endl;
}