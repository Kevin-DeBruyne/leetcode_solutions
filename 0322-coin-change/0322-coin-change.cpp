class Solution {
public:
    int help(vector<int>& coins, int amount, int n,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(n==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return INT_MAX-1;;
            }
        }
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        int pick=INT_MAX;
        int notPick=help(coins, amount, n-1,dp);
        if(coins[n]<=amount){
            pick=1+help(coins, amount-coins[n], n,dp);
        }
        return dp[amount][n]=min(pick,notPick);
    }
    // int rhelp(vector<int>& coins, int amount, int n){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(n==0){
    //         if(amount%coins[0]==0){
    //             return amount/coins[0];
    //         }
    //         else{
    //             return INT_MAX-1;
    //         }
    //     }
    //     int pick=INT_MAX;
    //     int notPick=rhelp(coins, amount, n-1);
    //     if(coins[n]<=amount){
    //         pick=1+rhelp(coins, amount-coins[n], n);
    //     }
    //     return min(pick,notPick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(10001, vector<int>(13,-1));
        if(help(coins, amount, n-1,dp)==2147483646) return -1;
        // return rhelp(coins, amount, n-1);
        return help(coins, amount, n-1,dp);
    }
};