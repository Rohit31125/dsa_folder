// que 45 Leetcode
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.   Medium

#include<iostream>
using namespace std;
#include<vector>
class Solution {
private:
    void solve(vector<int> nums,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            //backtrack
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
         int index = 0;
         solve(nums,index,ans);
         return ans;
    }
};