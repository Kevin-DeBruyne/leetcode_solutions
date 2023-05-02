//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isC=false;
    void dfs(int node, vector<int> adj[], vector<int>& vis, int parent){
        vis[node]=1;
        // cout<<node<<" "<<parent<<endl;
        for(auto x:adj[node]){
            if(vis[x]==0 && x!=parent){
                dfs(x, adj, vis, node);
                vis[x]=1;
            }
            else if(x!=parent && vis[x]==1){
                isC=true;
                return;
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i ,adj, vis, -1);
            }
        }
        return isC;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends