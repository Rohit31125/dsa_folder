#include<unordered_map>
#include<iostream>
using namespace std;
int main(){
}
class Solution{   
public:
    // int solve(int index,int A[],int n,int diff){
    //     if(index<0){
    //         return 0;
    //     }
    //     int ans = 0;
    //     for(int j = index-1;j>=0;j--){
    //         if(A[index] - A[j] ==diff){
    //             ans = max(ans, 1+ solve(j,A,n,diff));
    //         }
    //     }
    //     return ans;
    // }
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2){
            return n;
        }
        // int ans = 0;
        // for(int i = 0;i<n;i++){
        //     for(int j =i+1;j<n;j++){
        //         ans = max(ans,2+solve(i,A,n,A[j]-A[i]));
                
        //     }
        // }
        int ans = 0;
        unordered_map<int,int> dp[n+1];
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                int diff = A[i] - A[j];
                int cnt  =1;
                
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1+cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
    
};