//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int dp[1001][1001];
  int lcs(string A, string R, int l1, int l2){
      if(l1==0 || l2==0){
          return 0;
      }
      if(dp[l1-1][l2-1]!=-1){
          return dp[l1-1][l2-1];
      }
      if(A[l1-1]==R[l2-1]){
          return dp[l1-1][l2-1]=1+lcs(A, R, l1-1, l2-1);
      }
      else{
          return dp[l1-1][l2-1]=max(lcs(A, R, l1-1, l2), lcs(A, R, l1, l2-1));
      }
  }
    int longestPalinSubseq(string A) {
        string R=A;
        reverse(R.begin(), R.end());
        int l1, l2;
        memset(dp, -1, sizeof(dp));
        l1=R.length();
        l2=A.length();
        return lcs(A, R, l1, l2);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends