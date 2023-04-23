//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int& area, bool& yes){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n){
            yes=false;
            return;    
        }
        if(vis[i][j]==1 || grid[i][j]==0){
            return;
        }
        area++;
        vis[i][j]=1;
        dfs(i+1, j, grid, vis, area, yes);
        dfs(i, j+1, grid, vis, area, yes);
        dfs(i-1, j, grid, vis, area, yes);
        dfs(i, j-1, grid, vis, area, yes);
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<int>> vis( m , vector<int> (n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area=0;
                bool yes=true;
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(i, j, grid, vis, area, yes);
                    if(yes){
                        res+=area;  
                    }
                    
                }
            }
        }
    return res;    
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends