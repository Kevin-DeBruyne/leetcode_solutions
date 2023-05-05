//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<int>>& vis){
        int m=mat.size();
        int n=mat[0].size();
        if(i<0 || j<0 || i>=m || j>=n){
            return;
        }
        if(mat[i][j]=='X' || vis[i][j]==1){
            return;
        }
        mat[i][j]='M';
        vis[i][j]=1;
        dfs(i+1,j, mat, vis);
        dfs(i,j+1, mat, vis);
        dfs(i-1,j, mat, vis);
        dfs(i,j-1, mat, vis);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n, vector<int>(m,0));
        for (int i = 0; i < n;i++){
            int j=0;
            if(mat[i][j]=='O'){
                  dfs(i,j,mat, vis);
            }
        }
        for (int i = 0; i < m; i++)
        {
            int j=0;
            if(mat[j][i]=='O'){
                  dfs(j,i,mat, vis);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int j=m-1;
            if(mat[i][j]=='O'){
                  dfs(i,j,mat, vis);
            }
        }
        for (int i = 0; i < m; i++)
        {
            int j=n-1;
            if(mat[j][i]=='O'){
                  dfs(j,i,mat, vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='M'){
                    mat[i][j]='O';
                }
                else{
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends