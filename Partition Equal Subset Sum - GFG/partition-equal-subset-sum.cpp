//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool help(int N, int arr[], int sum, vector<vector<int>>&dp){
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
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        vector<vector<int>>dp(201, vector<int>(20000+1,-1));
        sum=sum/2;
        return help(N-1, arr, sum, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends