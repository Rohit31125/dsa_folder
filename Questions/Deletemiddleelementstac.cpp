#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
void solve(int count,stack<int>&inputStack,int size){
   if(count==size/2){
      inputStack.pop();
      return;
   }
   int num = inputStack.top();
   inputStack.pop();
   solve(count+1,inputStack,size);
   inputStack.push(num);
   
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(count,inputStack,N);
   
}
int main(){
}