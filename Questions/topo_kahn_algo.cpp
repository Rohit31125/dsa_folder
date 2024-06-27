#include <unordered_map>
#include <queue>
#include <vector>
#include <list>

std::vector<int> topologicalSort(std::vector<std::vector<int>> &edges, int v, int e) {
    std::unordered_map<int, std::list<int>> adjlist;
    std::queue<int> q;

    // Build the adjacency list
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }

    // Initialize indegrees of all vertices
    std::vector<int> indegree(v, 0);

    // Compute indegrees
    for (const auto& node : adjlist) {
        for (int neighbour : node.second) {
            indegree[neighbour]++;
        }
    }

    // Push all vertices with 0 indegree into the queue
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS
    std::vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        // Decrease the indegree of neighbours
        for (int neighbour : adjlist[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Check for cycle
    if (ans.size() != v) {
        // Return an empty list if there is a cycle
        return {};
    }

    return ans;
}


