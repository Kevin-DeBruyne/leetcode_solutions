//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
    int help(int n, int target, vector<int>&arr, vector<vector<int>>&dp){
    // int help(int n, int target, vector<int>&arr){
        if(n==0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int notTake=help(n-1, target, arr,dp);
        int take=0;
        if(arr[n]<=target){
            take=help(n-1, target-arr[n], arr,dp);
            // int take=help(n-1, target-arr[n], arr);
            // int notTake=help(n-1, target, arr);
            // return take+notTake;
        }
        return dp[n][target]=(take+notTake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(auto x:arr){
            sum+=x;
        }
        int target=(d+sum)/2;
        if(sum-d<0 || (d+sum)%2!=0){
            return 0;
        }
        vector<vector<int>>dp(501, vector<int>(target+1, -1));
        return help(n-1, target, arr,dp );
        // return help(n-1, target, arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends