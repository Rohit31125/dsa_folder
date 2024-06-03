#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution 
{
    private:
    bool knows(int a,int b,vector<vector<int> >& M){
        if(M[a][b]==1){
            return true;
        }
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i = 0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(a,b,M)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int ans = s.top();
        int countzero=0;
        int countone = 0;
        for(int i = 0;i<n;i++){
            if(M[ans][i]==0)
            countzero++;
            }
        
        if(countzero!=n){
            return -1;
        }
        for(int i = 0;i<n;i++){
            if(M[i][ans]==1)
            countone++;
        }
        if(countone!=n-1){
            return -1;
        }
        return ans;
        
    }
};