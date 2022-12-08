class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int curr=0;
        int reach=nums[curr];
        curr++;
        cout<<reach<<endl;
        while(curr<nums.size() && curr<=reach){
            cout<<reach<<" ";
            reach=max(reach,nums[curr]+curr);
            curr++;
        }
        cout<<endl;
        int n=nums.size();
        cout<<curr<<endl;
        if(curr>=n){
            return true;
        }
        return false;
    }
};