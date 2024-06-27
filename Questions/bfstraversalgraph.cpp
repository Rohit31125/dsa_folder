#include<iostream>
#include<vector>
using namespace std;
    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <list>
    #include <queue>

    using namespace std;

    void solve(vector<vector<int>> &adj, unordered_map<int, list<int>> &adjlist) {
        for (int i = 0; i <adj.size(); i++) {
            int u = adj[i][0];
            int v = adj[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }

    void bfs(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int frontnode = q.front();
            q.pop();

            ans.push_back(frontnode);

            for (auto i : adjlist[frontnode]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
        // Write your code here.
        unordered_map<int, list<int>> adjlist;
        vector<int> ans;
        unordered_map<int, bool> visited;

        // Initialize the visited map
        for (int i = 0; i <n; i++) {
            visited[i] = false;
        }

        solve(adj, adjlist);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(adjlist, visited, ans, i);
            }
        }
        return ans;
    }


