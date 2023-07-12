class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& candidates, int target,  vector<int>&temp,int ind){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            help(candidates, target-candidates[ind], temp, ind);
            temp.erase(temp.begin()+temp.size()-1);
        }
        help(candidates, target, temp, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        help(candidates, target, temp,0);
        return ans;
    }
};