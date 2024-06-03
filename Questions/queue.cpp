#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *next;
    int s;
    int n;
    int freespot;
    NStack(int N, int S)
    {
        s=S;
        n=N;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
            //initialise top
        for(int i = 0;i<n;i++){
            top[i]=-1;
        }
        //intialise next
        for(int i = 0;i<s;i++){
            next[i]=i+1;
        }
        //initialize last element of next
        next[s-1]=-1;
        //intialise freespot
        freespot = 0;
    }
 

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
       if(freespot==-1){
           return false;
       }
       //find index

       int index = freespot;
        //updating freespot
       freespot = next[index];
        //inserting element into the array
       arr[index]  = x;
        //update next
       next[index] = top[m-1];
        //update top
       top[m-1] = index;

       return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1){
            return -1;
        }
       int  index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};