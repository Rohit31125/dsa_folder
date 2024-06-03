#include<iostream>
using namespace std;
#include <bits/stdc++.h>
string replaceSpaces(string &str) {
	string s;
	for(int i = 0;i<str.size();i++){
		if(str[i]==' '){
			s.append("@40");
                }
				 else {
                        s.push_back(str[i]);
                }
        }
	str = s;
	return str;

}
int main(){
}