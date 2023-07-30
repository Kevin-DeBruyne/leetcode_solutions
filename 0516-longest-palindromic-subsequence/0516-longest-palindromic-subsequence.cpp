class Solution {
public:
    int dp[1001][1001];
    int lcs(string &s, string &r ,int l1, int l2){
        if(l1==0 || l2==0){
            return 0;
        }
        if(dp[l1-1][l2-1]!=-1){
            return dp[l1-1][l2-1];
        }
        if(s[l1-1]==r[l2-1]){
            return dp[l1-1][l2-1]=1+lcs(s, r, l1-1, l2-1);
        }
        else{
            return dp[l1-1][l2-1]=max(lcs(s, r ,l1-1, l2),lcs(s, r, l1, l2-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(), r.end());
        int l1=s.length();
        int l2=r.length();
        memset(dp, -1, sizeof(dp));
        return lcs(s, r, l1, l2);
    }
};