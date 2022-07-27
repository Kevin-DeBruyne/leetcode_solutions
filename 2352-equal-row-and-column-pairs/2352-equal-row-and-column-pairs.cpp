class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
            mp[temp]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            if(mp.count(temp)){
                
                count+=mp[temp];
            }
        }
        return count;
        
    }
};