class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis,bool &bahar){
        int M=grid.size();
        int N=grid[0].size();
        if(i<0 || j<0 || i>=M || j>=N){
            bahar=true;
            return;
        }
        if(vis[i][j]==1 || grid[i][j]==1){
            return;
        }
        vis[i][j]=1;
        dfs(i+1, j, grid, vis,bahar);
        dfs(i, j+1, grid, vis,bahar);
        dfs(i-1, j, grid, vis,bahar);
        dfs(i, j-1, grid, vis,bahar);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int M=grid.size();
        int N=grid[0].size();
        vector<vector<int>> vis( M , vector<int> (N, 0)); 
        int res=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                bool bahar=false;
                if(grid[i][j]==0 && vis[i][j]==0){
                    dfs(i, j, grid, vis, bahar);
                    if(!bahar){
                        res++;
                    }
                }
            }
        }
        return res;
    }
    
};