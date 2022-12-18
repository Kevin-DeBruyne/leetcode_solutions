class Solution {
public:
    vector<vector<int>>solve(vector<int>& nums){
        if(nums.size()==0){
            return {{}};
        }
        vector<int>temp;
        for(int i=1;i<nums.size();i++){
            temp.push_back(nums[i]);
        }        
        vector<vector<int>>pushing;
        vector<vector<int>>vec_t=subsetsWithDup(temp);
        for(auto x:vec_t){
            pushing.push_back(x);
        }
        for(auto x:vec_t){
            vector<int>hello=x;
            hello.push_back(nums[0]);
            pushing.push_back(hello);
        }
        return pushing;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        for(auto x:solve(nums)){
            sort(x.begin(), x.end());
            st.insert(x);
        }
        vector<vector<int>>ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};