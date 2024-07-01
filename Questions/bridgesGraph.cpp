#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &low, vector<int> &disc,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adjlist,
         unordered_map<int, bool> &visited) {
    visited[node] = true;
    low[node] = disc[node] = timer++;

    for (auto nbr : adjlist[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!visited[nbr]) {
            dfs(nbr, node, timer, low, disc, result, adjlist, visited);
            low[node] = min(low[node], low[nbr]);
            // Check if there is a bridge
            if (low[nbr] > disc[node]) {
                result.push_back({node, nbr});
            }
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    int timer = 0;
    unordered_map<int, bool> visited;
    vector<int> low(v, -1);
    vector<int> disc(v, -1);
    vector<vector<int>> result;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, -1, timer, low, disc, result, adjlist, visited);
        }
    }

    return result;
}
