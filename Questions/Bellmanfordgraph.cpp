#include<iostream>
using namespace std;
#include<vector>
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e8);

    dist[src]=0;

    for(int i =1;i<=n;i++){
        //traverse on edge list
        for(int j = 0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u]!=1e9 && ((dist[u] + wt) <dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }
   
    
    return dist;

    // bool flag = 0;
    // for(int i =1;i<=n;i++){
    //     //traverse on edge list
    //     for(int j = 0;i<m;i++){
    //         int u = edges[i][0];
    //         int v = edges[i][1];
    //         int wt = edges[i][2];

    //         if((dist[u]!=1e9) && ((dist[u] + wt) <dist[v])){
    //             flag = 1;
    //         }
    //     }
    // }
    // if(flag==0){
    //     return dist[dest];
    // }
    // return -1;
    // for checking negative cycle but not present in this 
    // question so commenting out

}