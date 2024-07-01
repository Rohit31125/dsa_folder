#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin >> n;
        // vector<int> dp(n+1);
        int prev = 1;
        int prev1 = 0;
        if(n==0){
                return prev1;
        }
        
        // for (int i = 2; i <= n; i++) {
        //         dp[i] = dp[i-1] + dp[i-2];
                    
        // }
        for(int i = 2;i<=n;i++){
                int curr = prev + prev1;
                prev1 = prev;
                prev = curr;
        }
          cout << prev <<endl;

          
        
        return 0;
}