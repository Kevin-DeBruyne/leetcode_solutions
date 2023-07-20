class Solution {
public:
    int help(vector<int>& coins, int amount, int n,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(n==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        int pick=0;
        int notPick=help(coins, amount, n-1,dp);
        if(coins[n]<=amount){
            pick=help(coins, amount-coins[n], n,dp);
        }
        return dp[amount][n]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(50001, vector<int>(301,-1));
        return help(coins, amount, n-1,dp);
    }
    
};