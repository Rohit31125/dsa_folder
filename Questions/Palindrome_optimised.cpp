// que 125 palindrome leetcode

#include <string>
using namespace std;
    
class Solution {
public:
    bool isvalid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z');
    }

    char lowercase(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return c;
        } else {
            return c - 'A' + 'a';
        }
    }

    bool isPalindrome(string s) {
        string str;

        for (int i = 0; i < s.size(); i++) {
            if (isvalid(s[i])) {
                str.push_back(lowercase(s[i]));  // Assign the result of lowercase back to the string
            }
        }

        for (int j = 0; j < str.size(); j++) {
            str[j] = lowercase(str[j]);  // Corrected: Assign the result of lowercase back to the string
        }

        int sta = 0;
        int e = str.size() - 1;
        while (sta <= e) {
            if (str[sta] != str[e]) {
                return false;
            } else {
                sta++;
                e--;
            }
        }

        return true;
    }
};
