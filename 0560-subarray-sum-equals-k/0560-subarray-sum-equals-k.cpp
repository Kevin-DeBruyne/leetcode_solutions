class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int pre=0;
        int cnt=0;
        mp[pre]=1;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            // if(pre==k){
            //     cnt++;
            // }
            if(mp.find(pre-k)!=mp.end()){
                cnt+=mp[pre-k];
            }
            mp[pre]++;
        }
    return cnt;
    }
};