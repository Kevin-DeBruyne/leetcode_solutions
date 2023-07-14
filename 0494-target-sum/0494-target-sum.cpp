class Solution {
public:
    // int help(vector<int>&nums, int t, int n){
    int help(vector<int>&nums, int t, int n, vector<vector<int>>&dp){
        if(n==0){
            if(nums[0]==0 && t==0) return 2;
            if(nums[0]==t || t==0) return 1;
            return 0;
        }
        if(dp[n][t]!=-1) return dp[n][t];
        int take=0;
        int notTake=help(nums, t, n-1, dp);
        if(nums[n]<=t){
            take=help(nums, t-nums[n], n-1,dp);
        }
        return dp[n][t]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        int t=(target+sum)/2;
        int n=nums.size();
        
        if((target+sum)%2==1) return 0;
        if (t<0) return 0;
        vector<vector<int>>dp(21, vector<int>(20001,-1));
        return help(nums, t, n-1, dp);
    }
};