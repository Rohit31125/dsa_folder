// sum of two arrays ----- coding ninjas

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 
vector<int> reverse(vector<int> rev){
	int s=0 ;
	int e = rev.size()-1;
	while(s<=e){
		swap(rev[s++],rev[e--]);
	}
	return rev;
	
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
	int j = m-1;
	int carry = 0;
	int sum;
	vector<int> ans;
	while(i>=0 && j>=0){
		int v = a[i];
		int g = b[j];
		sum = v + g + carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while(i>=0){
		int sum = a[i] + carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;

	}
	while(j>=0){
		int sum = b[j] + carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
		
	}
    while (carry != 0) {
                int sum = b[j] + carry;
                carry = sum / 10;
                sum = sum % 10;
                ans.push_back(sum);
        }
        return reverse(ans);
}

int main(){
}