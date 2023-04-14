//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis, int &cnt){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        cnt++;
        vis[i][j]=1;
        dfs(grid, i+1, j, vis, cnt);
        dfs(grid, i, j+1, vis, cnt);
        dfs(grid, i-1, j, vis, cnt);
        dfs(grid, i, j-1, vis, cnt);
        dfs(grid, i+1, j+1, vis, cnt);
        dfs(grid, i-1, j-1, vis, cnt);
        dfs(grid, i+1, j-1, vis, cnt);
        dfs(grid, i-1, j+1, vis, cnt);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int cnt=0;
                    dfs(grid, i, j, vis, cnt);
                    ans=max(ans, cnt);  
                    
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends