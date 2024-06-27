#include<iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <string>

using namespace std;

bool iscyclebfs(int src, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited) {
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        for (auto neighbour : adjlist[frontnode]) {
            if (visited[neighbour]==true && neighbour != parent[frontnode]) {
                return true;
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontnode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    // Write your code here.

    unordered_map<int, list<int>> adjlist;
    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
unordered_map<int, bool> visited;

    for (int i = 1; i <=n; i++) {
        if (!visited[i]) {
            bool ans = iscyclebfs(i, adjlist, visited);
            if (ans==1) {
                return "Yes";
            }
        }
    }
    return "No";
}


