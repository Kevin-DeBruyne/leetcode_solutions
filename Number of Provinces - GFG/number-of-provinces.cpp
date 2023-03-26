//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int n=adj.size();
        vector<int>l[n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(adj[i][j]==1 && i!=j){
					l[i].push_back(j);
					l[j].push_back(i);
				}
			}
		}
        vector<int> vis(n, 0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                        q.pop();
                        for(auto x:l[node]){
                            if(vis[x]==0){
                                vis[x]=1;
                                q.push(x);
                            }
                    }
                }
            }
        }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends