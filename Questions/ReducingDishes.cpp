#include<vector>
#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int main(){
}
class Solution {
public:
    // int solve(vector<int> &satisfaction,int index,int time,int n,vector<vector<int>> &dp){
    //     if(index==n){
    //         return 0;
    //     }
    //     if(dp[index][time]!=-1){
    //         return dp[index][time];
    //     }
    //     int ans = INT_MIN;
    //     int include = (satisfaction[index] * (1+time)) + solve(satisfaction,index+1,time+1,n,dp);
    //     int exclude = 0 + solve(satisfaction,index+1,time,n,dp);
    //     ans = max(include,exclude);
    //     dp[index][time] = ans;
    //     return dp[index][time];
    // }
    //   this is the most optimised idk how
    //  int solveopt(vector<int> &satisfaction,int index,int time,int n){
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //     for(int index = n-1 ;index>=0;index--){
    //         for(int time = index ;time>=0;time--){
    //             int ans = INT_MIN;
    //             int include = (satisfaction[index] * (1+time)) + dp[index+1][time+1];
    //             int exclude = 0 + dp[index+1][time];
    //             ans = max(include,exclude);
    //             dp[index][time] = ans;
    //         }
    //     }
        
     
    //     return dp[0][0];
    // }
    int solveoptimised(vector<int> &satisfaction,int index,int time,int n){
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        for(int index = n-1 ;index>=0;index--){
            for(int time = index ;time>=0;time--){
                int ans = INT_MIN;
                int include = (satisfaction[index] * (1+time)) + next[time+1];
                int exclude = 0 + next[time];
                curr[time] = max(include,exclude);
                
            }
            next = curr;
        }
        
     
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveoptimised(satisfaction,0,0,n);
        
    }
};