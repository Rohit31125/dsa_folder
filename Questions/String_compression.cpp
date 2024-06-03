// que 443 - String compression - Leetcode 


// note - We need to specify the number of column when passing a 2D array as a parameter because 
// the compiler needs it to allocate the necessary addresses for the 2D array;


#include<iostream>
#include<vector>
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansindex = 0;
        int n = chars.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            chars[ansindex++] = chars[i];
            
            int count  = j - i;
            if (count > 1) {
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansindex++] = ch;
                }
            }
            i = j;
        }
        return ansindex;
    }
};

using namespace std;
int main(){
}