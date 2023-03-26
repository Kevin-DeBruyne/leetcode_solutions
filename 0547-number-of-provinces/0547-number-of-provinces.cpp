class Solution {
public:
    void dfs(vector<int>& vis, vector<vector<int>>& adj, int source){
        vis[source]=1;
        for(auto x:adj[source]){
            if(!vis[x]){
                dfs(vis,adj, x);
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
        vector<int> vis(n, 0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(vis,adj,i);
            }
        }
        return ans;
    }
};