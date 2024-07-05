#include<vector>
#include<iostream>
using namespace std;
int main(){
}
class Solution {
    // int solve(vector<vector<int>> &mat,int i,int j,vector<vector<int>> &dp,int &maxi){
    //     if(i >= mat.size() || j >= mat[0].size()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int down = solve(mat,i+1,j,dp,maxi);
    //     int diagonal = solve(mat,i+1,j+1,dp,maxi);
    //     int right = solve(mat,i,j+1,dp,maxi);
    //     if(mat[i][j]==1){
    //         dp[i][j] = 1 + min(down,min(diagonal,right));
    //         maxi = max(maxi,dp[i][j]);
    //         return dp[i][j];
    //     }
    //     else{
    //         return dp[i][j]=0;
    //     }
        
    // }
       int solveTab(vector<vector<int>> &mat,int i,int j,int &maxi,int n,int m){
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        

        for(int i = row-1;i>=0;i--){
            for(int j = col-1;j>=0;j--){
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                int right = dp[i][j+1];
                 if(mat[i][j]==1){
                    dp[i][j] = 1+ min(down,min(diagonal,right));
                    maxi = max(maxi,dp[i][j]);
            }
            else{
                 dp[i][j]=0;    
            }
                
                }
                
            }
            return dp[0][0];
           
            
        
   
        
       
        
    }
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxi = 0;
    
        int ans = solveTab(mat,0,0,maxi,n,m);
        return maxi;
    }
};