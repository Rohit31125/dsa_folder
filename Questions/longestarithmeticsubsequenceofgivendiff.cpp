#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
int main(){
}
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans  =0;
        unordered_map<int,int> dp;

        for(int i = 0;i<arr.size();i++){
            int temp = arr[i] - difference;
            int tempans = 0;


            if(dp.count(temp)){
                tempans = dp[temp];
            }
            dp[arr[i]] = 1 + tempans;

            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};