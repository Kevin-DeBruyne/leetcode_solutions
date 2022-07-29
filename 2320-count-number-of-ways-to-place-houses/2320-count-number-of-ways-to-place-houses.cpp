class Solution {
public:
    int countHousePlacements(int n) {
        
        long long mod=1e9+7;
        long long a=1;
        long long b=1;
        for(int i=0;i<n;i++){
            int c = (a+b)%mod;
            a=b;
            b=c;
        }
        long long ans=(b*b)%mod;
        return ans;
    }
};