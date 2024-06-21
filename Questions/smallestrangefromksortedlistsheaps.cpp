#include<queue>
#include<limits.h>
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;
        node(int data,int i,int j){
        this->data = data;
        row  = i;
        col = j; 
    
     }
 
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int maxi = INT_MIN;
    int mini = INT_MAX;
    priority_queue<node*,vector<node*>,compare> minheap;

    for(int i =0;i<k;i++){
        int element = a[i][0];
        maxi = max(element,maxi);
        mini = min(element,mini);
        minheap.push(new node(element,i,0));
    }
    int start = mini;
    int end = maxi;

    while(!minheap.empty()){
        node* top = minheap.top();
        minheap.pop();

        mini = top->data;

        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }
        if(top->col+1 < n){
            maxi = max(maxi,a[top->row][top->col +1]);
            minheap.push(new node(a[top->row][top->col+1],top->row,top->col +1));

        }
        else{
            break;
        }
        
    }

    return end-start+1;

}