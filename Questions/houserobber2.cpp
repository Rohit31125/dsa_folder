#include <bits/stdc++.h> 
using namespace std;

long long int solve(vector<int> &valueInHouse, int n){
    if (n == 0) return 0;
    if (n == 1) return valueInHouse[0];

    vector<long long int> dp(n, 0);
    dp[0] = valueInHouse[0];
    dp[1] = max(valueInHouse[0], valueInHouse[1]);

    for(int i = 2; i < n; i++){
        long long int inc = dp[i-2] + valueInHouse[i];
        long long int excl = dp[i-1];
        dp[i] = max(inc, excl);
    }
    return dp[n-1];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();

    if(n == 1){
        return valueInHouse[0];
    }

    vector<int> first(valueInHouse.begin(), valueInHouse.end() - 1); // excluding the last house
    vector<int> second(valueInHouse.begin() + 1, valueInHouse.end()); // excluding the first house

    return max(solve(first, first.size()), solve(second, second.size()));
}

