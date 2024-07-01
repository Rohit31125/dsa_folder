#include <bits/stdc++.h> 
#include<vector>
#include<iostream>
using namespace std;
int main(){
}
#define MOD 1000000007
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a,int b){
    return (a%MOD* 1LL * b%MOD)%MOD;
}
int solve(int n,int k,vector<int> &dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] =  add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
    return dp[n];

}
int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int> dp(n+1,-1);
    int ans = solve(n,k,dp);
    return ans;
}