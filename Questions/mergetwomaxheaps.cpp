#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  private:
  int countindex(Node* root){
      if(root==NULL){
          return 0;
      }
      int ans = countindex(root->left) + countindex(root->right) + 1;
      return ans;
  }
  bool isCbt(Node* root,int index,int count){
      if(root==NULL){
          return true;
      }
      
      if(index >=count){
          return false;
      }
      else{
          bool left = isCbt(root->left,2*index+1,count);
          bool right = isCbt(root->right,2*index+2,count);
            return left && right;
      }
    
  }
  bool isMaxorder(Node* root){
      if(root==NULL){
          return true;
      }
      if(root->left==NULL && root->right==NULL){
          return true;
      }
      if(root->right == NULL){
          return root->data > root->left->data;
      }
      else{
         bool left = isMaxorder(root->left);
          bool right = isMaxorder(root->right);
          return (left && right && (root->data > root->left->data && root->data > root->right->data));
      }
      
  }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int count = countindex(tree);
        if(isCbt(tree,index,count) && isMaxorder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};