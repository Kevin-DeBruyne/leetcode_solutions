class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        long long n=nums.size();
        unordered_set<long long>st;
        sort(nums.begin(), nums.end());
        for(auto x:nums){
            st.insert(x);
        }
        vector<int>vec;
        long long ans=0;
        if(nums[0]>316){
            return -1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>316){
                
                break;
            }
            long long temp=1;
            if(st.find(nums[i]*nums[i])!=st.end()){
                long long curr=nums[i]*nums[i];
                temp++;
                while(true){
                    if(st.find(curr*curr)!=st.end()){
                        temp++;
                        curr=curr*curr;
                    }                    
                    else{
                        break;
                    }
                }
            }
            ans=max(ans, temp);
        }
        if(ans==1){
            return -1;
        }
        return ans;
    }
};