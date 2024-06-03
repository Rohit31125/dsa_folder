#include<iostream>
// que -Check if string is a palindtrome -- codingninjas
#include <bits/stdc++.h>
#include<vector>
bool checkPalindrome(string s) {
      vector<char> str;
       for(int i = 0;i<s.size();i++){
         if(isalpha(s[i]) || isdigit(s[i])){
           if(isupper(s[i])){
             char temp = tolower(s[i]);
             str.push_back(temp);
           } else
             str.push_back(s[i]);
           
         }
         }
         int se = 0;
         int e = str.size()-1;
         while(se<e){
           if(str[se]!=str[e]){
             return false;
           }
           else{
             se++;
             e--;
           }
         }
         return true;

}
using namespace std;
int main(){
}