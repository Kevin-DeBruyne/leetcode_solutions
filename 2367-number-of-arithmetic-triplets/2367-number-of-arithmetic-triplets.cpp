class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int count=0;
        int cnt[201]={};
        for(auto x:nums){
            if(x>=2*diff){
                count+=cnt[x-diff]&&cnt[x-2*diff];
            }
            cnt[x]=true;
        }
        return count;
    }
};