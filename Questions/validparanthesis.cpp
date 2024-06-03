// valid parenthesis in coding ninjas
#include <bits/stdc++.h> 
bool isValidParenthesis(string expression)
{
 stack<char> str;
 for(int i = 0;i<expression.length();i++){
     char ch = expression[i];

    //opening brackets

     if(ch=='(' || ch=='{' || ch=='['){
         str.push(ch);
     }
     else{
         //closing brackets
         if(!str.empty()){
             char top = str.top();
             if((ch==')' && top=='(') || (ch=='}' && top=='{')
             || (ch==']' && top=='[')){
                 str.pop();
             }
             else{
                 return false;
             }
         }
         else{
             return false;
         }
     }
 }
 if(str.empty()){
     return true;
 }
 else{
     return false;
 }
}
