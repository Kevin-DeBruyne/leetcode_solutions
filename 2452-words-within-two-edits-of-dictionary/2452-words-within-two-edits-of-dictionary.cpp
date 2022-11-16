class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        int l=queries[0].size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=0;
                for(int k=0;k<l;k++){
                    if(queries[i][k]!=dictionary[j][k]){
                        temp++;
                    }
                }
                if(temp<=2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};