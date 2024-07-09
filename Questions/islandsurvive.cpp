#include<iostream>
using namespace std;
int main(){
}
class Solution {
public:
    int minimumDays(int S, int N, int M) {
        // Calculate the number of Sundays in S days
        int sunday = S / 7;
        
        // Calculate the number of days on which you can buy food
        int buyingdays = S - sunday;
        
        // Calculate the total amount of food needed for S days
        int totalfood = S * M;
        
        // Calculate the minimum number of days needed to buy the required food
        int ans = (totalfood + N - 1) / N; // Correct ceiling division
        
        // Check if the number of buying days is sufficient
        if (ans <= buyingdays) {
            return ans;
        } else {
            return -1;
        }
    }
};