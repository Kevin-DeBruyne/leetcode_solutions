class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0;
        int jump=0;
        int curr=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(i+nums[i]>curr){
                curr=i+nums[i];
            }
            if(i==reach){
                jump++;
                reach=curr;
            }
        }
        return jump;
    }
};