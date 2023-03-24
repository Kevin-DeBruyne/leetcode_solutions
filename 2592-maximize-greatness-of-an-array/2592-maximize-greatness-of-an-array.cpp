class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset<int>s;
        for(auto &x:nums){
            s.insert(x);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            auto ub=s.upper_bound(nums[i]);
            if(ub!=s.end()){
                ans++;
                s.erase(ub);
            }
            else{
                s.erase(s.begin());
            }
        }
        return ans;
    }
};