#include<iostream>
using namespace std;
#include<queue>
#include<map>

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
  Node* nodetoparentmapping(Node* root,int target,map<Node*,Node*> &nodetoparent){
      Node* result = NULL;
      queue<Node*> q;
      q.push(root);
      nodetoparent[root] = NULL;
      
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          if(front->data==target){
              result = front;
          }
          if(front->left){
              nodetoparent[front->left] = front;
              q.push(front->left);
          }
          if(front->right){
              nodetoparent[front->right] = front;
              q.push(front->right);
          }
      }
      return result;
  }
  int burntree(Node* root,map<Node*,Node*> &nodetoparent){
      map<Node*,bool> visited;
      queue<Node*> q;
      q.push(root);
      visited[root] = true;
      
    
      int count = 0;
      
      while(!q.empty()){
            bool flag = 0;
          int size =q.size();
          for(int i=0;i<size;i++){
              Node* front = q.front();
              q.pop();
              if(front->left && !visited[front->left]){
                   flag =1;
                  q.push(front->left);
                  visited[front->left] = 1;
                  
                 
              }
               if(front->right && !visited[front->right]){
                   flag =1;
                    q.push(front->right);
                  visited[front->right] = 1;
                 
                  
              }
              if(nodetoparent[front] && !visited[nodetoparent[front]]){
                   flag =1;
                  q.push(nodetoparent[front]);
                  visited[nodetoparent[front]]=1;
                 
              }
          }
          if(flag==1){
              count++;
          }
      }
      return count;
  }
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> nodetoparent;
        Node* targetnode = nodetoparentmapping(root,target,nodetoparent);
        int ans = burntree(targetnode,nodetoparent);
        return ans;
        
    }
};