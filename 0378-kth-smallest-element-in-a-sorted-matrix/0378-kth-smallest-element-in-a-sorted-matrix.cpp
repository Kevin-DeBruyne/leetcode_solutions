class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                pq.push(matrix[i][j]);
            }
        }
        int i=1;
        while(i<k){
            pq.pop();
            i++;
        }
        return pq.top();
    }
};