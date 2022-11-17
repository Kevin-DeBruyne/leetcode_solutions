class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>pre;
        vector<int>post;
        int mul_pre=1;
        for(auto x:nums){
            mul_pre*=x;
            pre.push_back(mul_pre);
        }
        int mul_post=1;
        for(int i=nums.size()-1;i>=0;i--){
            mul_post*=nums[i];
            post.push_back(mul_post);
        }
        reverse(post.begin(), post.end());
        for(auto x:pre){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:post){
            cout<<x<<" ";
        }
        ans.push_back(post[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(pre[i-1]*post[i+1]);
        }
        ans.push_back(pre[n-2]);
        return ans;
    }
};