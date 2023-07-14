//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
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
    int findTargetSumWays(vector<int>&nums ,int target) {
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends