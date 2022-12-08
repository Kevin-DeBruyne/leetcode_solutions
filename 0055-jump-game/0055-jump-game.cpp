class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=0;
        int reach=nums[curr];
        curr++;
        while(curr<nums.size() && curr<=reach){
            reach=max(reach,nums[curr]+curr);
            curr++;
        }
        int n=nums.size();
        if(curr>=n){
            return true;
        }
        return false;
    }
};