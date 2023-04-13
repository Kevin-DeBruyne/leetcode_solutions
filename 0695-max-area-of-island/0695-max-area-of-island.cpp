class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        cnt++;
        dfs(grid, i-1, j, vis);
        dfs(grid, i, j+1, vis);
        dfs(grid, i+1, j, vis);
        dfs(grid, i, j-1, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(grid, i,j, vis);
                    cout<<cnt<<endl;
                    ans=max(ans, cnt);
                    cnt=0;
                }
            }
        }
        // dfs(grid, 0,7, vis);
        // cout<<cnt<<endl;
        return ans;
    }
};