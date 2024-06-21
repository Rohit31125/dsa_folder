#include<algorithm>
#include<iostream>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
   
    sort(arr.begin(),arr.end());
     string a = arr[0];
    string b = arr[n-1];
    if(n==0){
        return "";
    }
    if(n==1){
        return arr[0];
    }
   for(int i =0;i<a.size();i++){
       if(a[i]!=b[i]){
           break;
       }
       char ch = a[i];
       ans.push_back(ch);
   } 
   return ans;
}


