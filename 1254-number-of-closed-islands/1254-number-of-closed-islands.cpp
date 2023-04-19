class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, bool& yes){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n){
            yes=false;
            return;
        }
        if(grid[i][j]==1 || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        dfs(i+1, j , grid, vis, yes);
        dfs(i, j+1 , grid, vis, yes);
        dfs(i-1, j , grid, vis, yes);
        dfs(i, j-1 , grid, vis, yes);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int cnt=0;
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    bool yes=true;
                    dfs(i, j , grid, vis, yes);
                    if(yes){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};