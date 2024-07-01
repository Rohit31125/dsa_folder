#include <bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
int main(){
}
int solve(vector<int> &nums,int n){
    vector<int> dp(n,-1);
    dp[0] =  nums[0];
    for(int i = 1;i<n;i++){
        int inc = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(inc,excl);
    }
    return dp[n-1];
} 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return solve(nums,n);
}