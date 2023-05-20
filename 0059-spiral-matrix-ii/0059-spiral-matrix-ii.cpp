class Solution
{
    public:
        void dfs(vector<vector<int>>&res,int i, int j, int cnt, bool goup){
            int n=res.size();
            if(i<0 || j<0 || i>=n || j>=n || res[i][j]!=0){
                return;
            }
            cnt++;
            res[i][j]=cnt;
            if(goup) dfs(res, i-1 , j, cnt, true);
            dfs(res, i, j+1, cnt, false);
            dfs(res, i+1, j, cnt, false);
            dfs(res, i, j-1, cnt, false);
            dfs(res, i-1 , j, cnt, true);
        }
        vector<vector < int>> generateMatrix(int n)
        {
            vector<vector<int>> res(n, vector<int> (n, 0));
           	int cnt=0;
            int i=0;
            int j=0;
            bool goup=false;
            dfs(res, i, j, cnt, goup);
            return res;
        }
};