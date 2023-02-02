class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, nums[i]);
            pre[i]=(maxi);
        }
        int mini=1000001;
        for(int i=n-1;i>=0;i--){
            mini=min(mini, nums[i]);
            suf[i]=(mini);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>pre[i-1] && nums[i]<suf[i+1]){
                ans+=2;
            }
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                ans++;
            }
        }
        
        return ans;
    }
};