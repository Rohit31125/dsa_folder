#include<iostream>
using namespace std;
#include<vector>
void dfs(int node,unordered_map<int,bool> &visited,
unordered_map<int,list<int>> &adjlist,vector<int> &component){
    //answer store
    component.push_back(node);
    //marking visited
    visited[node]=true;
    //calling recursive call for all the connected nodes
    for(auto i :adjlist[node]){
        if(!visited[i]){
            dfs(i,visited,adjlist,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>> adjlist;
    unordered_map<int,bool> visited;

    vector<vector<int>> ans;
    //prepare adjlist
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    //for all nodes call dfs if not visited
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjlist,component);
            ans.push_back(component);
        }
    }

    return ans;
}