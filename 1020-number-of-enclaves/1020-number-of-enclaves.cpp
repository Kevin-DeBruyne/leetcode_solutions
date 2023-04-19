class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, bool& yes, int& area){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n){
            yes=false;
            return;
        }
        if(grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        area++;
        dfs(i+1, j , grid, vis, yes,area);
        dfs(i, j+1 , grid, vis, yes, area);
        dfs(i-1, j , grid, vis, yes ,area);
        dfs(i, j-1 , grid, vis, yes, area);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int cnt=0;
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    bool yes=true;
                    int area=0;
                    dfs(i, j , grid, vis, yes, area);
                    cout<<area<<endl;
                    if(yes){
                        cnt++;
                        res+=area;
                    }
                }
            }
        }
        return res;
    }
};