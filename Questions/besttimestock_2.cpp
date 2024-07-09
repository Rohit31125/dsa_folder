#include<iostream>
#include<vector>
using namespace std;
int main(){
}
class Solution {
public:
    // int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp){
    //     int n = prices.size();
    //     if(index == n){
    //         return 0;
    //     }
    //     if(dp[index][buy]!=-1){
    //         return dp[index][buy];
    //     }
    //     int buystock = 0;
    //     int notbuystock = 0;
    //     int profit = 0;
    //     if(buy){
    //         buystock = -prices[index] + solve(index+1,0,prices,dp);
    //         notbuystock = 0 + solve(index+1,1,prices,dp);
    //         profit = max(buystock,notbuystock);
    //     }
    //     else{
    //         int sellstock  =  prices[index] + solve(index+1,1,prices,dp);
    //         int notsellstock = 0 + solve(index+1,0,prices,dp);
    //         profit = max(sellstock,notsellstock);
    //     }
    //     return dp[index][buy] = profit;

    // }
    // int solvetab(vector<int> &prices){
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,0));
        
    //     int buystock = 0;
    //     int notbuystock = 0;
    //     int profit = 0;
    //     for(int index = n-1;index >=0;index--){
    //         for(int buy = 0;buy<=1;buy++){
    //             if(buy){
    //         buystock = -prices[index] + dp[index+1][0];
    //         notbuystock = 0 + dp[index+1][1];
    //         profit = max(buystock,notbuystock);
    //     }
    //     else{
    //         int sellstock  =  prices[index] + dp[index+1][1];
    //         int notsellstock = 0 + dp[index+1][0];
    //         profit = max(sellstock,notsellstock);
    //     }
    //     dp[index][buy] = profit;
    //         }
    //     }
        
    //     return dp[0][1];

    // }
     int solveopt(vector<int> &prices){
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        
        int buystock = 0;
        int notbuystock = 0;
        int profit = 0;
        for(int index = n-1;index >=0;index--){
            for(int buy = 0;buy<=1;buy++){
                if(buy){
            buystock = -prices[index] + next[0];
            notbuystock = 0 + next[1];
            profit = max(buystock,notbuystock);
        }
        else{
            int sellstock  =  prices[index] + next[1];
            int notsellstock = 0 + next[0];
            profit = max(sellstock,notsellstock);
        }
        curr[buy] = profit;
        
            }
            next = curr;
        }
        
        return next[1];

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // return solve(0,1,prices,dp);
        return solveopt(prices);
    }
};