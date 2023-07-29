//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int help(vector<int> &vec, int n, int ind){
        if(n==0){
            return 0;
        }
        if(ind==0){
            return n*vec[0];
        }
        if(dp[n][ind]!=-1){
            return dp[n][ind];
        }
        int notTake=help(vec, n, ind-1);
        int take=INT_MIN;
        int rodlen=ind+1;
        if(rodlen<=n){
            take=vec[ind]+help(vec, n-rodlen, ind);
            // return dp[n][ind]=max(vec[ind]+help(vec, n-ind, ind), help(vec, n, ind-1));
        }
        return dp[n][ind]=max(take, notTake);
    }
    int cutRod(int price[], int n) {
        vector<int>vec;
        for(int i=0;i<n;i++){
            vec.push_back(price[i]);
        }
        int ind=n-1;
        memset(dp, -1, sizeof(dp));
        return help(vec, n, ind);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends