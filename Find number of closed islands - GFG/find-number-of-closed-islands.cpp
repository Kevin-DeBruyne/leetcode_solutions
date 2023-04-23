//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&vis,bool &bahar){
        int M=matrix.size();
        int N=matrix[0].size();
        if(i<0 || j<0 || i>=M || j>=N){
            bahar=true;
            return;
        }
        if(vis[i][j]==1 || matrix[i][j]==0){
            return;
        }
        vis[i][j]=1;
        dfs(i+1, j, matrix, vis,bahar);
        dfs(i, j+1, matrix, vis,bahar);
        dfs(i-1, j, matrix, vis,bahar);
        dfs(i, j-1, matrix, vis,bahar);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> vis( N , vector<int> (M, 0)); 
        int res=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                bool bahar=false;
                if(vis[i][j]==0 && matrix[i][j]==1){
                    dfs(i, j, matrix, vis, bahar);
                    if(!bahar){
                        res++;
                    }
                }
            }
        }
        return res;
    }
    
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends