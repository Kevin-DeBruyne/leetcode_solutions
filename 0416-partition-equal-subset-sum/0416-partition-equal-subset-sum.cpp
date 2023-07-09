class Solution {
public:
    bool help(int N,vector<int>&arr, int sum, vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(N==0){
            return arr[0]==sum;
        }
        if(dp[N][sum]!=-1){
            return dp[N][sum];
        }
        if(sum<arr[N]){
            return dp[N][sum]=help(N-1, arr, sum,dp);
        }
        else{
            return dp[N][sum]=help(N-1, arr, sum-arr[N],dp) || help(N-1, arr, sum,dp); 
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int N=nums.size();
        for(int i=0;i<N;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(201, vector<int>(20000+1,-1));
        // int dp[101][5*1000000+1];
        sum=sum/2;
        return help(N-1, nums, sum, dp);
    }
};