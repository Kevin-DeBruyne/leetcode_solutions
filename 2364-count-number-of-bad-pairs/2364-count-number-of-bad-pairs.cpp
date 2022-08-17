class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long ans=0;
        map<long long,long long>m;
        for(int i=0;i<n;i++){
            m[nums[i]-i]++;

        }
        long long y=0;
        for(auto it=m.begin();it!=m.end();it++){
            long long a=it->second;    
            y+=(a*(a-1)/2);
            
        }
        ans+=(n*(n-1)/2);
        ans-=y;
        return ans;
        
    }
};