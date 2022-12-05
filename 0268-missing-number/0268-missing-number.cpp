class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int maxi=0;
        for(auto x:nums){
            maxi+=x;
        }
        return sum-maxi;
    }
};