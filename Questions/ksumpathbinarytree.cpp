#include<iostream>
#include<vector>
using namespace std;
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  private:
    void solve(Node* root,int &count,vector<int> path,int k,int sum){
        if(root==NULL){
            return;
        }
        path.push_back(root->data);
        solve(root->left,count,path,k,sum);
        solve(root->right,count,path,k,sum);
        int size = path.size();
        for(int i = size-1;i>=0;i-- ){
            sum = sum + path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
  public:
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count = 0;
        int sum = 0;
        solve(root,count,path,k,sum);
        return count;
    }
};