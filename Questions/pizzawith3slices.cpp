#include<vector>
#include<iostream>
using namespace std;
int main(){
}
class Solution {
public:
    int solve(int index,int endindex,vector<int> &slices,int n,vector<vector<int>> &dp){
        if(n==0 || index > endindex){
            return 0;
        }
        if(dp[index][n]!=-1){
            return dp[index][n];
        }
        int include = slices[index] + solve(index+2,endindex,slices,n-1,dp);
        int exclude = 0 + solve(index+1,endindex,slices,n,dp);
        dp[index][n] = max(include,exclude);
        return dp[index][n];
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k,vector<int>(k,-1));
        vector<vector<int>> dp2(k,vector<int>(k,-1));
        int ans1 = solve(0,k-2,slices,k/3,dp1);
        int ans2 = solve(1,k-1,slices,k/3,dp2);
        return max(ans1,ans2);
    }
};