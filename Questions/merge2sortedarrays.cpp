
// que 88 of coding ninjas

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m;
        int j = 0;
        while(s<nums1.size()){
            nums1[s] = nums2[j];
            s++;
            j++; 
        
    }
    sort(nums1.begin(),nums1.end());
    }
};
int main(){
}