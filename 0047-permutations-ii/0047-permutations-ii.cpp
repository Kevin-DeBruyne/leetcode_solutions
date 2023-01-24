class Solution {
public:
    set<vector<int>>ans;
	    void help(vector<int> que, vector<int> asf){
	        int n=que.size();
	        if(que.size()==0){
	            ans.insert(asf);
	            return;
	        }
	        for(int i=0;i<que.size();i++){
	            vector<int>roq;
	            int ch=que[i];
	            for(int j=0;j<que.size();j++){
	                if(j!=i){
	                    roq.push_back(que[j]);
	                }
	            }
	            vector<int>temp=asf;
	            temp.push_back(ch);
	            help(roq, temp);
	        }   
	    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>asf;
            help(nums,asf);
            vector<vector<int>>res;
            for(auto x:ans){
                res.push_back(x);
            }
            return res;
    }
};