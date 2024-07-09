#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;
int main(){
}
class Solution {
public:
    int solve(int index,int buy, vector<int> &prices,int limit
    ,vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(index == n){
            return 0;
        }
        if(limit == 0){
            return 0;
        }
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int buykaro = 0;
        int skipbuykaro = 0;
        int profit = 0;
        if(buy){
            buykaro = -prices[index] + solve(index+1,0,prices,limit,dp);
            skipbuykaro = 0 + solve(index+1,1,prices,limit,dp);
            profit = max(buykaro,skipbuykaro);
        }
        else{
            int sellkaro = prices[index] + solve(index+1,1,prices,limit-1,dp);
            int skipsell = 0 + solve(index+1,0,prices,limit,dp);
            profit = max(sellkaro,skipsell);
        }
        return dp[index][buy][limit] = profit;
        

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,prices,2,dp);
    }
};