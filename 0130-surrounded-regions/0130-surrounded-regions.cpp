class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m=board.size();
        int n=board[0].size();
        if(i<0 || j<0 || i>=m || j>=n){
            return;
        }
        if(board[i][j]=='X' || vis[i][j]==1){
            return;
        }
        board[i][j]='M';
        vis[i][j]=1;
        dfs(i+1,j, board, vis);
        dfs(i,j+1, board, vis);
        dfs(i-1,j, board, vis);
        dfs(i,j-1, board, vis);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        for (int i = 0; i < m;i++){
            int j=0;
            if(board[i][j]=='O'){
                  dfs(i,j,board, vis);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int j=0;
            if(board[j][i]=='O'){
                  dfs(j,i,board, vis);
            }
        }
        for (int i = 0; i < m; i++)
        {
            int j=n-1;
            if(board[i][j]=='O'){
                  dfs(i,j,board, vis);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int j=m-1;
            if(board[j][i]=='O'){
                  dfs(j,i,board, vis);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='M'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};