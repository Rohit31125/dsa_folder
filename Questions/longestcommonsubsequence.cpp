#include<vector>
#include<iostream>
using namespace std;
int main(){
}
class Solution {
public:
    // int solve(string a,string b,int i,int j,vector<vector<int>> &dp){
    //     if(i==a.length()){
    //         return 0;
    //     }
    //     if(j==b.length()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int ans  = 0;
    //     if(a[i]==b[j]){
    //         ans = 1 + solve(a,b,i+1,j+1,dp);
    //     }
    //     else{
    //         int ans1 = solve(a,b,i+1,j,dp);
    //         int ans2 = solve(a,b,i,j+1,dp);
    //         ans = max(ans1,ans2); 
    //     }
    //     return dp[i][j] = ans;
    // }
    // int solvetab(string a,string b){
    //     vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));

    //     for(int i = a.length()-1;i>=0;i--){
    //         for(int j = b.length()-1;j>=0;j--){
    //             int ans  = 0;
    //     if(a[i]==b[j]){
    //         ans = 1 + dp[i+1][j+1];
    //     }
    //     else{
    //         ans = max(dp[i + 1][j], dp[i][j + 1]);
    //     }
    //     dp[i][j] =  ans;
    //         }

    //     }
    //     return dp[0][0];
    // }
   int solveopt(string a, string b) {
        int m = a.length();
        int n = b.length();
        
        // Initialize the vectors based on the length of b (text2)
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        
        // Iterate over the strings in reverse order
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[j + 1];
                } else {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length();
        // int n1 = text2.length();
        // vector<vector<int>> dp(n,vector<int>(n1+1,-1));
        return solveopt(text1,text2);
    }
};