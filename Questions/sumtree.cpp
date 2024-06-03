#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};
class Solution
{
    private:
    pair<bool,int> issumtreefast(Node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        pair<bool,int> left = issumtreefast(root->left);
        pair<bool,int> right = issumtreefast(root->right);
        bool isleftsum = left.first;
        bool isrightsum = right.first;
        bool cond = root->data == left.second + right.second;
        pair<bool,int> ans;
        if(isleftsum && isrightsum && cond){
            ans.first = true;
            ans.second = 2*root->data;
        }
       else{
           ans.first = false;
       }
       return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         return issumtreefast(root).first;
         
    }
    };