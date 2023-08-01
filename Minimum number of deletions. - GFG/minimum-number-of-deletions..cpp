//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int dp[1001][1001];
int lps(string &str, string &rev, int n1, int n2){
    if(n1==0 || n2==0){
        return 0;
    }
    if(dp[n1-1][n2-1]!=-1){
        return dp[n1-1][n2-1];
    }
    if(str[n1-1]==rev[n2-1]){
        return dp[n1-1][n2-1]=1+lps(str, rev, n1-1, n2-1);
    }
    else{
        return dp[n1-1][n2-1]=max(lps(str, rev, n1-1, n2), lps(str, rev, n1, n2-1));
    }
}

int minDeletions(string str, int n) { 
    string rev=str;
    reverse(rev.begin(), rev.end());
    memset(dp, -1, sizeof(dp));
    return n-lps(str, rev, n, n);
} 