class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&vis){
        int M=grid.size();
        int N=grid[0].size();
        if(i<0 || j<0 || i>=M || j>=N){
            return;
        }
        if(vis[i][j]==1 || grid[i][j]=='0'){
            return;
        }
        vis[i][j]=1;
        dfs(i+1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j-1, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int M=grid.size();
        int N=grid[0].size();
        vector<vector<int>> vis( M , vector<int> (N, 0)); 
        // for(auto x:vis){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        int res=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i, j, grid, vis);
                    res++;
                }
            }
        }
        return res;
    }
};