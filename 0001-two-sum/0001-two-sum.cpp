class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>st;
        int n=nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(st.find(target-nums[i])!=st.end()){
                vec.push_back(i);
                vec.push_back(st[target-nums[i]]);
                break;
            }
            else{
                st[nums[i]]=i;
            }
        }
    return vec;
    }
};