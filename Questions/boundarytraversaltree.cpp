#include<iostream>
using namespace std;
#include<vector>
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
     private:
    void traverseleft(Node* root,vector<int> &ans){
        if(root==NULL || (root->right==NULL && root->left==NULL) ){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseleft(root->left,ans);
        }
        else{
            traverseleft(root->right,ans);
        }
    }
    void traverseleaf(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        if(root->right==NULL && root->left==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }
    void traverseright(Node* root,vector<int> &ans){
         if(root==NULL || (root->right==NULL && root->left==NULL) ){
            return;
        }
        if(root->right){
             traverseright(root->right,ans);
        }
        else{
              traverseright(root->left,ans);
        }
        ans.push_back(root->data);
    }
public:
   
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
    
        traverseleft(root->left,ans);
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
        traverseright(root->right,ans);
        return ans;
    }
};