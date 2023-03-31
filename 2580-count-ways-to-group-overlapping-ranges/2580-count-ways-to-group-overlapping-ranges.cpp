class Solution {
public:
    long long MOD=1e9+7;
    long long calcPower(long long base, long long power)  //modulo exponentation
    {
        long long ans = 1;
        while(power )
        {
                ans = (ans * 2) % MOD; 
                power--; 
        }
        return ans;
    }
    long long countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n=ranges.size();
        int temp=1;
        long long ans=2;
        int maxi=ranges[0][1];
        for(int i=1;i<n;i++){
            if(ranges[i][0]<=maxi){
                maxi=max(maxi, ranges[i][1]);
            }
            else{
                temp++;
                maxi=ranges[i][1];
                ans=(ans*2)%MOD;
            }
        }
        // cout<<temp<<endl;
        return ans;
    }
};