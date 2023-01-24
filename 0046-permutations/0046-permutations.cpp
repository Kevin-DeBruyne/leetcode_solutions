class Solution {
public:
    vector<vector<int>> help(vector<int>& ques){
        int n=ques.size();
        if(ques.size()==0){
            return {{}};
        }
        vector<vector<int>>temp;
        for(int i=0;i<ques.size();i++){
            int ch=ques[i];
            vector<int>roq;
            for(int j=0;j<ques.size();j++){
                if(j!=i){
                    roq.push_back(ques[j]);
                }
            }
            vector<vector<int>> ans=help(roq);
            for(auto x:ans){
                x.push_back(ch);
                temp.push_back(x);
            }
        }
        return temp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return help(nums);
    }
};