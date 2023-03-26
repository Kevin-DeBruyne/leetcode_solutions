class Solution {
public:
    void bfs(int n, vector<vector<int>>adj, vector<int>&vis){
        queue<int>q;
        q.push(n);
        vis[n]=1;
        while(!q.empty()){
            int node=q.front();
                q.pop();
                for(auto x:adj[node]){
                    if(vis[x]==0){
                        vis[x]=1;
                        q.push(x);
                    }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
		vector<vector<int>>adj(n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(isConnected[i][j]==1 && i!=j){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
        for(int i=0;i<n;i++){
            for(auto y:adj[i]){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        vector<int> vis(n, 0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                bfs(i, adj,vis);
            }
        }
        return ans;
    }
};