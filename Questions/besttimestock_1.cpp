#include<vector>
#include<iostream>
using namespace std;
int main(){
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxi = prices[0];
        for(int i = 1;i<prices.size();i++){
            int diff = prices[i] - maxi;
            profit = max(profit,diff);
            maxi = min(maxi,prices[i]); 
        }
        return profit;
    }
};