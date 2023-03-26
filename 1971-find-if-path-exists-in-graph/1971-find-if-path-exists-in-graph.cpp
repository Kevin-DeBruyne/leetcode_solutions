class Solution {
public:
    bool ans=false;
    void dfs(vector<int>& vis, int n, vector<vector<int>>& adj, int source, int dest){
        vis[source]=1;
        for(auto x:adj[source]){
            if(!vis[x]){
                if(x==dest){
                   ans=true; 
                }
                dfs(vis, n, adj, x, dest);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n, 0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(source==destination){
            return true;
        }
        dfs(vis, n,adj, source, destination);
        return ans;
    }
};