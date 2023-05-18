class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>nums(n,0);
        int cnt=0;
        for(auto q:queries){
            int i=q[0];int newColor=q[1];
            if(nums[i] && i-1>=0 && nums[i-1]==nums[i]){
                cnt--;
            }
            if(nums[i] && i+1<n && nums[i+1]==nums[i]){
                cnt--;
            }
            nums[i]=newColor;
            if(i-1>=0 && nums[i-1]==nums[i]){
                cnt++;
            }
            if(i+1<n && nums[i+1]==nums[i]){
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};