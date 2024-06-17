#include<iostream>
using namespace std;
#include<limits>
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
class info{
    public:
    int maxi;
    int mini;
    int size;
    bool isBST;

};
info solve(TreeNode* root,int &maxsize){
    if(root==NULL){
        return {INT_MIN,INT_MAX,0,true};
    }
    info left = solve(root->left,maxsize);
    info right = solve(root->right,maxsize);

    info currnode;

    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data,right.maxi);
    currnode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data >left.maxi && root->data < right.mini)){
        currnode.isBST = true;
    }
    else{
        currnode.isBST = false;
    }
    if(currnode.isBST){
        maxsize = max(maxsize,currnode.size);
    }
    return currnode;
    
    }
int largestBST(TreeNode * root){
    // Write your code here.
    int maxsize = 0;
    info temp = solve(root,maxsize);
    return maxsize;
}