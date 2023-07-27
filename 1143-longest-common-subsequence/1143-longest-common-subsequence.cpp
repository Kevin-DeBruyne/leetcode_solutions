class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size();
        int t2=text2.size();
        memset(dp, -1,sizeof(dp));
        for(int i=0;i<t1;i++){
            for(int j=0;j<t2;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<t1+1;i++){
            for(int j=1;j<t2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }          
            }
        }
        if(dp[t1][t2]==-1){
            return 0;
        }
        return dp[t1][t2];
    }
};