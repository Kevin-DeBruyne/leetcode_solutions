class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for(auto x:nums){
        //     cout<<x<<" ";
        // }
        int i=0;
        int j=nums.size()-1;
        int maxi=0;
        while(i<j){
            maxi=max(maxi, nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};