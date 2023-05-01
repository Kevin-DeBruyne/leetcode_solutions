class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int tot=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    tot++;
                }
            }
        }
        int days=0;
        int res=0;
        while(!q.empty()){
            int k=q.size();
            res+=k;
            while(k--){
                pair<int,int>node=q.front();
                int i=node.first;int j=node.second;
                q.pop();
                if(i+1>=0 && j>=0 && i+1<m && j<n && grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if(i-1>=0 && j>=0 && i-1<m && j<n && grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if(i>=0 && j+1>=0 && i<m && j+1<n && grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }
                if(i>=0 && j-1>=0 && i<m && j-1<n && grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
            }
            if(!q.empty())days++;
            // days++;
        }
        if(res==tot){
            return days;
        }
        else{
            return -1;
        }
    }
    
};