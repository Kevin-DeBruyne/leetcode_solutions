class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int result=n;
        for(int i=0;i<n;i++){
            result=result^i;
            result=result^nums[i];
        }
        return result;
        
    }
};