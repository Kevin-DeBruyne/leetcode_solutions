//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&vis){
        int M=grid.size();
        int N=grid[0].size();
        if(i<0 || j<0 || i>=M || j>=N){
            return;
        }
        if(vis[i][j]==1 || grid[i][j]=='O'){
            return;
        }
        vis[i][j]=1;
        dfs(i+1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j-1, grid, vis);
    }
    int xShape(vector<vector<char>>& grid) 
    {
        int M=grid.size();
        int N=grid[0].size();
        vector<vector<int>> vis( M , vector<int> (N, 0)); 
        int res=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='X' && vis[i][j]==0){
                    dfs(i, j, grid, vis);
                    res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends