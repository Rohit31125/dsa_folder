#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create the adjacency list
    unordered_map<int, list<pair<int, int>>> adjlist;

    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    // Initialize distances with INT_MAX
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Set to store (distance, node)
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        // Get the node with the smallest distance
        auto top = *(st.begin());
        int nodedistance = top.first;
        int topnode = top.second;

        // Remove the smallest distance node from the set
        st.erase(st.begin());

        // Update the distances of neighboring nodes
        for(auto neighbour : adjlist[topnode]){
            if(nodedistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // If found, erase the existing distance record
                if (record != st.end()) {
                  st.erase(record);
                }

                // Update the distance
                dist[neighbour.first] = nodedistance + neighbour.second;
                // Insert the updated distance into the set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}