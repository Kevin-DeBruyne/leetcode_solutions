//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    void dfs(int i, int j, int d1, int d2, vector<vector<int>>& grid, vector<vector<int>>& vis, bool& yes){
        int m=grid.size();
        if(i<0 || j<0 || i>=m || j>=m || grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        if(i==d1 && j==d2){
            yes=true;
            return;
        }
        dfs(i+1, j, d1, d2, grid, vis, yes);
        dfs(i, j+1, d1, d2, grid, vis, yes);
        dfs(i-1, j, d1, d2, grid, vis, yes);
        dfs(i, j-1, d1, d2, grid, vis, yes);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int s1,s2;
        int d1,d2;
        vector<vector<int>>vis(m, vector<int>(m, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    s1=i;
                    s2=j;
                }
                if(grid[i][j]==2){
                    d1=i;
                    d2=j;
                }
            }
        }
        bool yes=false;
        dfs(s1, s2, d1, d2, grid, vis, yes);
        if(yes){
            return true;
        }
        else{
            return false;
        }
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends