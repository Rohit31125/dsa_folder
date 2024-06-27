#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
bool solve(int node,unordered_map<int,bool> &visited,
unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &dfsvisited){
  visited[node]=1;
  dfsvisited[node]=1;

  for(auto neighbour : adjlist[node]){
    if (!visited[neighbour]) {
      bool cycledetected = solve(neighbour, visited, adjlist, dfsvisited);
       if(cycledetected){
        return true;
    }
     
      }
      else if(dfsvisited[neighbour]){
        return true;
      }
    
  }
  dfsvisited[node] =  0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adjlist;

  for(int i = 0;i<edges.size();i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adjlist[u].push_back(v);
    
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;

  for(int i = 1;i<=n;i++){
    if(!visited[i]){
      bool ans = solve(i,visited,adjlist,dfsvisited);
      if(ans==1){
        return true;
      }
    }
  }
  return false;
}