//que - coding ninjas    --  Subsequences of a string - same as the power set of a subset

#include<iostream>
using namespace std;
#include<vector>

#include <bits/stdc++.h> 
void solve(string str,string output,int index,vector<string>& ans){
  if (index >= str.size()) {
	  if(!output.empty())
    ans.push_back(output);
    return;
  }
  
  //exclude
  solve(str,output,index+1,ans);
  //include
  output.push_back(str[index]);
  solve(str,output,index+1,ans);
  
}
vector<string> subsequences(string str){
	
	vector<string> ans;
	string output;
	int index=0;
	solve(str,output,index,ans);
	return ans;
	
}
