#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

void toposort(int node, std::stack<int> &s, std::unordered_map<int, std::list<int>> &adjlist, std::vector<bool> &visited) {
    visited[node] = true;

    for (auto neighbour : adjlist[node]) {
        if (!visited[neighbour]) {
            toposort(neighbour, s, adjlist, visited);
        }
    }
    s.push(node);
}

std::vector<int> topologicalSort(const std::vector<std::vector<int>> &edges, int v, int e) {
    std::unordered_map<int, std::list<int>> adjlist;
    std::vector<bool> visited(v, false);
    std::stack<int> s;

    // Construct the adjacency list
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }

    // Perform topological sort
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            toposort(i, s, adjlist, visited);
        }
    }

    // Retrieve the sorted order
    std::vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


