//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int val, int newColor, vector<vector<int>>& vis){
        int m=image.size();
        int n=image[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n  || image[sr][sc]!=val || vis[sr][sc]==1){
            return;
        }
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        dfs(image, sr+1, sc, val, newColor, vis);
        dfs(image, sr, sc+1, val, newColor, vis);
        dfs(image, sr, sc-1, val, newColor, vis);
        dfs(image, sr-1, sc, val, newColor, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int val=image[sr][sc];
        dfs(image, sr, sc, val, newColor, vis);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends