class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            cnt++;
            return;
        }    
        if(vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        // cnt++;
        dfs(grid, i, j+1, vis);
        dfs(grid, i+1, j, vis);
        dfs(grid, i, j-1, vis);
        dfs(grid, i-1, j, vis);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int x,y;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    x=i;y=j;
                }
            }
        }
        dfs(grid, x, y, vis);
        return cnt;
    }
};