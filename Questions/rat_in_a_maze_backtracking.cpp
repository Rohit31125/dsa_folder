#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int newx,int newy,
vector < vector < int >> & arr,vector<vector<bool>> &vis,int n){
    if((newx>=0 && newx<n)&&(newy>=0 && newy<n) 
    &&(vis[newx][newy]!=1)&&arr[newx][newy]==1){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x,int y,vector < vector < int >> &arr,vector<string> &ans,
string path,vector<vector<bool>> &vis,int n){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    // 4 movements
    //if down
     vis[x][y]=1;
    if(isSafe(x+1,y,arr,vis,n)){
       
        solve(x+1,y,arr,ans,path+'D',vis,n);
    
    }
    //if left
    
     if(isSafe(x,y-1,arr,vis,n)){
        
        solve(x,y-1,arr,ans,path+'L',vis,n);

    }
    //if right
     if(isSafe(x,y+1,arr,vis,n)){
    
        solve(x,y+1,arr,ans,path+'R',vis,n);

    }
    //if up
     if(isSafe(x-1,y,arr,vis,n)){
        solve(x-1,y,arr,ans,path+'U',vis,n);
    }
        vis[x][y]=0;



}
vector < string > searchMaze(vector < vector < int >> & arr,int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path;
    if(arr[0][0]==0){
        return ans;
    }

    solve(0,0,arr,ans,path,visited,n);
    return ans;
}