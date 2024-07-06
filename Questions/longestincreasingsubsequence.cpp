// imp ques u need to have knowledge on how to do it
#include<iostream>
#include<vector>
using namespace std;
int main(){
}
class Solution {
public:
    // int solve(int n, int a[], int curr, int prev, vector<vector<int>> &dp) {
    //     if (curr == n) {
    //         return 0;
    //     }

    //     if (dp[curr][prev + 1] != -1) {
    //         return dp[curr][prev + 1];
    //     }

    //     int include = 0;
    //     if (prev == -1 || a[curr] > a[prev]) {
    //         include = 1 + solve(n, a, curr + 1, curr, dp);
    //     }

    //     int exclude = solve(n, a, curr + 1, prev, dp);

    //     dp[curr][prev + 1] = max(include, exclude);

    //     return dp[curr][prev + 1];
    // }
    int solveoptimal(int n,int a[]){
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i = 1;i<n;i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                int index =lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(n, a, 0, -1, dp);
        return solveoptimal(n,a);
    }
};