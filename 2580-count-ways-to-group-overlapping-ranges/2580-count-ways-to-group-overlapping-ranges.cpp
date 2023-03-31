class Solution {
public:
    long long mod=1e9+7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n=ranges.size();
        int temp=1;
        int maxi=INT_MIN;
        for(int i=1;i<n;i++){
            maxi=max(maxi, ranges[i-1][1]);
            if(ranges[i][0]<=maxi){
                continue; 
            }
            else{
                temp++;
            }
        }
        long long ans=1;
        for(int i=0;i<temp;i++){
            ans=(ans*2)%mod;
        }
        return ans%mod;
    }
};