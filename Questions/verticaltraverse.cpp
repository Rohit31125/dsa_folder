#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<map>
class solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int> >  temp = q.front();
            q.pop();
            Node* qfront = temp.first;
            int hordist = temp.second.first;
            int lvl = temp.second.second;
            nodes[hordist][lvl].push_back(qfront->data);
            if(qfront->left){
                q.push(make_pair(qfront->left,make_pair(hordist-1,lvl+1)));
            }
            if(qfront->right){
                q.push(make_pair(qfront->right,make_pair(hordist+1,lvl+1)));
            }
          
            
        }
          for(auto i: nodes){
                for(auto j : i.second){
                    for(auto k : j.second){
                        ans.push_back(k);
                    }
                }
            }
        return ans;
        
        
    }
};
