// insert at the end of the stack coding ninjas
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
}
void solve(stack<int>& stack,int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }
    int num = stack.top();
    stack.pop();
    solve(stack,x);
    stack.push(num);
} 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
