#include <bits/stdc++.h>
#include<iostream>
using namespace std;
bool findRedundantBrackets(string &s) {
    stack<char> stack;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if((c=='(') || (c=='+') ||(c=='-') || (c=='/')|| (c=='*')){
            stack.push(c);
        }
        else{
            bool  isredundant = true;
            if(c==')'){
                while(stack.top()!='('){
                    char c = stack.top();
                    if((c=='+') ||(c=='-') || (c=='/')|| (c=='*')){
                        isredundant =  false;
                       
                    }
                    stack.pop();
                    
                    
                }
            
                    if(isredundant==true){
                        return true;
                      
                    
                }
                  stack.pop();
                
            }
        }
    }
    return false;
}