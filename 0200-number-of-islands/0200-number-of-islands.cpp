class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]==1){
            return;
        }    
        vis[i][j]=1;
        dfs(grid, i-1, j, vis);
        dfs(grid, i, j+1, vis);
        dfs(grid, i, j-1, vis);
        dfs(grid, i+1, j, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        // bool vis[grid.size()][grid[0].size()]={{false}};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(grid, i ,j, vis);
                    count++;
                }
            }
        }
    return count;
    }
};