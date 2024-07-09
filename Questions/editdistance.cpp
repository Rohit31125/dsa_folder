#include<vector>
#include<iostream>
using namespace std;
int main(){
}
class Solution {
public:
    int solve(string a ,string b,int i,int j,vector<vector<int>> &dp){
        if(i==a.length()){
            return b.length() - j;
        }
        if(j ==b.length()){
            return a.length() - i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i]==b[j]){
             ans  = solve(a,b,i+1,j+1,dp);
        }
        else{
            int insertans = 1+solve(a,b,i,j+1,dp);
            int deleteans = 1+solve(a,b,i+1,j,dp);
            int replaceans = 1+solve(a,b,i+1,j+1,dp);

            ans = min(insertans,min(deleteans,replaceans));
        }
        return dp[i][j] = ans;
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};