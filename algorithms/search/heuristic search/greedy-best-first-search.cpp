#include <bits/stdc++.h>
#define MAX INT8_MAX

using namespace std;
ifstream in("input.txt");

int size, startNode, goalNode;
int graph[MAX][MAX];
bool visited[MAX];

// read data from file
void readData() {
    in >> size ;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            in >> graph[i][j];
        }

        visited[i] = false;
    }

    in >> startNode;
    in >> goalNode;
}

/**
 * get adjacent nodes of a node v
 * using a priority queue to have nodes ordered by cost
*/
void getAdjacent(int v, int row[MAX], priority_queue<pair<int, int>, 
                vector<pair<int, int>>>& adj) {
    for(int i = 0; i < size; i++) {
        if(row[i] >= 0) {
            adj.push(make_pair(row[i], i));
        }
    }
}

// greedy best first search
void best_first_search() {
    
    // put the nodes into a stack
    // permits to select the node with the lowest cost
    stack<int> s;
    s.push(startNode);
    visited[startNode] = true;

    while(!s.empty()) {
        int v = s.top();
        s.pop();

        // nodes expanded
        cout << v << " ";

        if(v == goalNode) {
            return;
        } else {
            priority_queue<pair<int, int>, 
                    vector<pair<int, int>>> adj;

            getAdjacent(v, graph[v], adj);

            while(!adj.empty()) {
                int x = adj.top().second;
                adj.pop();

                if(!visited[x]) {
                    visited[x] = true;
                    s.push(x);
                }
            } 
        }
    }
}

int main() {
    readData();
    best_first_search();
    cout << endl;
}
