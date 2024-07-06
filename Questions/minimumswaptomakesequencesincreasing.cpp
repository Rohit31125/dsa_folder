#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;
int main(){
}
class Solution {
public:
    int solve(vector<int> &nums1,vector<int> &nums2,int index,bool swapped,vector<vector<int>> &dp){
        if(index == nums1.size()){
            return 0;
        }
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        int ans = INT_MAX;
        if(swapped){
            swap(prev1,prev2);
        }
        //exclude
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans =  solve(nums1,nums2,index+1,0,dp);
        }
        //check
        
        //include
        if(nums1[index] > prev2 && nums2[index] > prev1){
            int swapped_ans = solve(nums1, nums2, index + 1, 1,dp);
            if (swapped_ans != INT_MAX) {
                ans = min(ans, 1 + swapped_ans);
        }
        }
        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n = nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        bool swapped = 0;
        return solve(nums1,nums2,1,swapped,dp);
    }
};