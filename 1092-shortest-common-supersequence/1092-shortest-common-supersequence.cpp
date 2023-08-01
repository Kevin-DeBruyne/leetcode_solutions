class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        int dp[1001][1001];
        string s=str1;
        int t1=s.size();
        string r=str2;
        int t2=r.size();
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
                if(s[i-1]==r[j-1]){
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
        string ans;
        ans="";
        while(t1>0 && t2>0){
            if(s[t1-1]==r[t2-1]){
                ans+=s[t1-1];
                t1--;
                t2--;
            }
            else{
                if(dp[t1-1][t2]>dp[t1][t2-1]){
                    ans+=s[t1-1];
                    t1--;
                }
                else{
                    ans+=r[t2-1];
                    t2--;
                }
            }
        }
        while(t1>0){
             
             ans+=str1[t1-1];
             t1--;
             
         } 
         while(t2>0){
             ans+=str2[t2-1];
             t2--;
             
             
         }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};