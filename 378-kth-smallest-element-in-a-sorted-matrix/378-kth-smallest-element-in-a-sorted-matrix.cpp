class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>vec;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vec.push_back(matrix[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        return vec[k-1];
    }
};