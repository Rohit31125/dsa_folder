#include<vector>
#include<iostream>
using namespace std;
int main(){
}
class Solution{
public:
    // bool solve(int index,int N,int arr[],int target,
    // vector<vector<int>> &dp){
    //     if(target < 0){
    //         return 0;
    //     }
    //     if(target == 0){
    //         return 1;
    //     }
    //     if(index >=N){
    //         return 0;
    //     }
    //     if(dp[index][target]!=-1){
    //         return dp[index][target];
    //     }
    //     int include = solve(index+1,N,arr,target - arr[index],dp);
    //     int exclude = solve(index+1,N,arr,target,dp);
    //     return dp[index][target] = include or exclude;
    // } 
        bool solvetab(int index,int N,int arr[],int target,int sum){
       
        vector<vector<int>> dp(N+1,vector<int>(target+1,0));
        for(int i = 0;i<=N;i++){
            dp[i][0]=1;
        }
        for(index = N-1;index>=0;index--){
            for(int t = 0;t<=target;t++){
                bool include = 0;
                if(t-arr[index]>=0){
                include = dp[index+1][t - arr[index]];
                }
                
                bool exclude = dp[index+1][t];
                dp[index][t] = include or exclude;
            }
        }
        return dp[0][sum/2];
         
    } 
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum  =0 ;
        for(int i =0;i<N;i++){
            sum += arr[i];  
        }
        if(sum & 1){
            return 0;
        }
        int target = sum/2;
        // vector<vector<int>> dp(N,vector<int>(target+1,-1));
        // return solve(0,N,arr,target,dp);
        return solvetab(0,N,arr,target,sum);
    }
};