class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, vector<vector<int>>&vis, int color,int val){
        int m=image.size();
        int n=image[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || image[sr][sc]!=val || vis[sr][sc]==1){
            return;
        }
        image[sr][sc]=color;
        vis[sr][sc]=1;
        dfs(image, sr+1, sc, vis, color, val);
        dfs(image, sr, sc+1, vis, color, val);
        dfs(image, sr, sc-1, vis, color, val);
        dfs(image, sr-1, sc, vis, color, val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int val=image[sr][sc];
        dfs(image, sr, sc, vis, color, val);
        return image;
    }
};