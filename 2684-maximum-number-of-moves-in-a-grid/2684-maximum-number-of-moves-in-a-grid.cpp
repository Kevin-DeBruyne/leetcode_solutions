class Solution {
public:
            vector<vector<int>>vis;
        int m;
        int n;
            int cnt=0;
            int best=0;
    void dfs(int i, int j, vector<vector<int>>& grid, int val){
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
        if(i-1>=0 and j+1<n)
        dfs(i-1, j+1, grid, val);
        if(j+1<n)
        dfs(i, j+1, grid, val);
        if(i+1<m and j+1<n)
        dfs(i+1, j+1, grid, val);
        vis[i][j]=0;
        cnt--;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<m;i++){
            int val=0;
            cnt=0;
            best=0;
            // cout<<grid[i][0]<<endl;
            dfs(i, 0, grid,val);
            // cout<<endl;
            maxi=max(best-1, maxi);
        }
        return maxi;
        }
    
};