// very important que according to instincts
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    int ans  = 0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;
    for(int day : days){
    
    
    while(!month.empty() && month.front().first +30 <=day){
        month.pop();
    }
    while (!week.empty() && week.front().first + 7 <= day) {
        week.pop();
    }

    month.push(make_pair(day, ans + cost[2]));
    week.push(make_pair(day, ans + cost[1]));

    ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }

    return ans;
    
}