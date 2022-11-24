class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            // set<int>st;
            int target=-nums[i];
            vector<int>temp;
            int l=i+1;
            int r=n-1;
            // if(nums[i]==nums[l]){
            //     continue;
            // }
            while(l<r){
                if(nums[l]+nums[r]>target){
                r--;
            }
            else if(nums[l]+nums[r]<target){
                l++;
            }
            else{
                temp.push_back(nums[i]);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                l++;
                r--;
                ans.insert(temp);
                temp.clear();
                
            }
            }
            // if(!temp.empty()){
            // }
        }
        vector<vector<int>>vec;
        for(auto x:ans){
            vec.push_back(x);
        }
    return vec;
    }
};