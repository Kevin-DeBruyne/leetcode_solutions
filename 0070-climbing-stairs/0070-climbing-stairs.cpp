class Solution {
public:
    std::vector<int> dp = std::vector<int>(46,-1);
    int climbStairs(int n) {
        if(n==1 || n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int one=climbStairs(n-1);
        int two=climbStairs(n-2);
        return dp[n]=one+two;
    }
};