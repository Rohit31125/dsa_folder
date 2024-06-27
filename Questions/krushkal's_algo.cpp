#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findparent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);  // Path compression
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findparent(parent, u);
    v = findparent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);

    makeset(parent, rank, n);

    int minweight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = findparent(parent, edges[i][0]);
        int v = findparent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v) {
            minweight += wt;
            unionset(u, v, parent, rank);
        }
    }
    return minweight;
}
