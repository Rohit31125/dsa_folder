#include<iostream>
#include<limits>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void solve(Node* root,int len,int &maxlen,int sum,int &maxsum){
        if(root==NULL){
            if(len>maxlen){
                maxlen=len;
                maxsum=sum;
            }
            else if(len==maxlen){
                maxsum=max(sum,maxsum);
                
            }
            return;
          
            
        }
          sum = sum + root->data;
            solve(root->left,len+1,maxlen,sum,maxsum);
            solve(root->right,len+1,maxlen,sum,maxsum);
    }    
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxlen=0;
        int sum=0;
        int maxsum=INT_MIN;
        solve(root,len,maxlen,sum,maxsum);
        return maxsum;
    }
};