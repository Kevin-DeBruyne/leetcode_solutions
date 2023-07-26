class Solution {
public:
    int dp[1001][1001];
    int help(string &text1, string &text2, int t1, int t2){
        if(t1==-1 || t2==-1){
            return 0;
        }
        if(dp[t1][t2]!=-1){
            return dp[t1][t2];
        }
        if(text1[t1]==text2[t2]){
            return dp[t1][t2]=1+help(text1, text2, t1-1, t2-1);
        }
        return dp[t1][t2]=max(help(text1, text2, t1-1, t2), help(text1, text2, t1, t2-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size();
        int t2=text2.size();
         memset(dp, -1, sizeof(dp));
        return help(text1, text2, t1-1, t2-1);
    }
};