/// sort stack without using loop and by using recursion coding 360 

#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

void sortedinsert(stack<int>& stack,int num){
	if(stack.empty() || (!stack.empty() && num > stack.top()) ){
		stack.push(num);
		return;
	}
	int n = stack.top();
	stack.pop();
	sortedinsert(stack,num);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	sortedinsert(stack,num);
	
}
