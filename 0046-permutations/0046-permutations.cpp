class Solution {
public:
    vector<vector<int>>temp;
    void help(vector<int>& ques, vector<int>& asf){
        if(ques.size()==0){
            temp.push_back(asf);
            return;
        }
        int n=ques.size();
        for(int i=0;i<ques.size();i++){
            int ch=ques[i];
            vector<int>roq;
            for(int j=0;j<ques.size();j++){
                if(j!=i){
                    roq.push_back(ques[j]);
                }
            }
            vector<int>temp2=asf;
            temp2.push_back(ch);
            help(roq, temp2);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vec{};
        help(nums, vec);
        return temp;
    }
};