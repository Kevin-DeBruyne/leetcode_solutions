class Solution {
public:
    vector<int>res;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int d=0;int l=0; int t=0; int r=matrix[0].size()-1;int b=matrix.size()-1;
        while(t<=b && l<=r){
            if(d==0){
                for(int i=l;i<=r;i++){
                    res.push_back(matrix[t][i]);
                }
                t++;
                d=1;
            }
            else if(d==1){
                for(int i=t;i<=b;i++){
                    res.push_back(matrix[i][r]);
                }
                r--;
                d=2;
            }
            else if(d==2){
                for(int i=r;i>=l;i--){
                    res.push_back(matrix[b][i]);
                }
                b--;
                d=3;
            }
            else{
                for(int i=b;i>=t;i--){
                    res.push_back(matrix[i][l]);
                }
                l++;
                d=0;
            }
        }
        return res;
    }
};