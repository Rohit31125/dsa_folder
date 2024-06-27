#include<unordered_map>
#include<queue>
#include<list>
#include<vector>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>> adjlist;
	for(int i = 0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adjlist[u].push_back(v);
		adjlist[v].push_back(u);

	}

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]= true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i : adjlist[front]){
                  if (!visited[i]) {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                  }
                }
	}
	vector<int> ans;
	int currnode = t;
	ans.push_back(t);

	while(currnode!=s){
		currnode = parent[currnode];
		ans.push_back(currnode);

	}
	reverse(ans.begin(),ans.end());
	return ans;
}
