class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<=nums[i]){
                ans+=nums[i]-nums[i+1]+1;
                nums[i+1]+=nums[i]-nums[i+1]+1;
                
            }
        }
        return ans;
    }
};