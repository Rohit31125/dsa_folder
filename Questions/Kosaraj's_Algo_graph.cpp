#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, stack<int> &s) {
    visited[node] = true;
    for (auto nbr : adjlist[node]) {
        if (!visited[nbr]) {
            dfs(nbr, adjlist, visited, s);
        }
    }
    // dfs topo logic
    s.push(node);
}

void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose) {
    visited[node] = true;
    for (auto nbr : transpose[node]) {
        if (!visited[nbr]) { // Corrected this line
            revdfs(nbr, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, const vector<vector<int>> &edges) {
    // Create the adjacency list
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }

    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, adjlist, visited, s);
        }
    }

    // Transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        visited[i] = false; // Reset visited for the second DFS
        for (auto nbr : adjlist[i]) {
            transpose[nbr].push_back(i);
        }
    }

    int count = 0;
    while (!s.empty()) {
        int front = s.top();
        s.pop();

        if (!visited[front]) {
            count++;
            revdfs(front, visited, transpose);
        }
    }

    return count;
}
