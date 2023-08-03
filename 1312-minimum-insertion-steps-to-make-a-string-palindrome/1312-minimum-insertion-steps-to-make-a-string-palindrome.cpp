class Solution {
public:
    int dp[501][501];
    int lcs(string &s, string &r, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n-1][m-1]!=-1){
            return dp[n-1][m-1];
        }
        if(s[n-1]==r[m-1]){
            return dp[n-1][m-1]=1+lcs(s, r, n-1, m-1);
        }
        else{
            return dp[n-1][m-1]=max(lcs(s, r, n, m-1), lcs(s, r, n-1, m));
        }
        
    }
    int minInsertions(string s) {
        string r=s;
        memset(dp, -1, sizeof(dp));
        reverse(r.begin(), r.end());
        int n=s.size();
        int m=r.size();
        return n-lcs(s, r, n, m);
    }
};