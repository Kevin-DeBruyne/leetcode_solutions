class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int val, int cnt, int& best){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]==1 || grid[i][j]<=val){
            return;
        }
        vis[i][j]=1;
        val=grid[i][j];
        grid[i][j]=0;
        cnt++;
        // cout<<val<<" : "<< cnt << " : " ;
        best=max(best, cnt);
        // cout << best<< "--";
        dfs(i-1, j+1, grid, vis, val, cnt, best);
        dfs(i, j+1, grid, vis, val, cnt, best);
        dfs(i+1, j+1, grid, vis, val, cnt, best);
        vis[i][j]=0;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<grid.size();i++){
            int val=0;
            int cnt=0;
            int best=0;
            // cout<<grid[i][0]<<endl;
            dfs(i, 0, grid, vis, val, cnt,best);
            // cout<<endl;
            maxi=max(best-1, maxi);
        }
        return maxi;
        }
    
};