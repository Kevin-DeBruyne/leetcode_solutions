class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>oneRow(m);
        vector<int>zeroRow(m);
        vector<int>oneCol(n);
        vector<int>zeroCol(n);
        vector<vector<int>>diff(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[j][i]){
                    oneCol[i]++;
                }
                zeroCol[i]=m-oneCol[i];
            }
            cout<<endl;
        }
        for(auto x:oneCol){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:zeroCol){
            cout<<x<<" ";
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    oneRow[i]++;
                }
                zeroRow[i]=n-oneRow[i];
            }
            cout<<endl;
        }
        for(auto x:oneRow){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:zeroRow){
            cout<<x<<" ";
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
            // cout<<endl;
        }
        return diff; 
        
    }
};