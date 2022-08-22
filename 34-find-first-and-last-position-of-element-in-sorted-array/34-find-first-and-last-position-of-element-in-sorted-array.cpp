class Solution {
public:
    bool check(vector<int>& nums, int target){
        int low=0;
        int n=nums.size();
        
        int high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
    
    void first(vector<int>& nums, int target, vector<int>& ans){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                if(mid==0 || nums[mid]!=nums[mid-1]){
                    ans.push_back(mid);
                    return;
                }
                else{
                    high=mid-1;
                }
            }
        }
    }
    void last(vector<int>& nums, int target, vector<int>& ans){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                if(mid==n-1 || nums[mid]!=nums[mid+1]){
                    ans.push_back(mid);
                    return;
                }
                else{
                    low=mid+1;
                }
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        if(!check(nums, target)){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        first(nums, target, ans);
        last(nums, target, ans);
        return ans;
    }
};