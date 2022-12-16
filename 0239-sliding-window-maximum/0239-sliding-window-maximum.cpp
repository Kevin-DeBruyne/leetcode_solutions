class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        if(k==1){
            return nums;
        }
        int n=nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);            
        }
        ans.push_back(dq.front());
        if(dq.front()==nums[i]){
                dq.pop_front();
        }
        i++;
        j++;
        while(j<n){
            while(!dq.empty() && nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            ans.push_back(dq.front());
            if(dq.front()==nums[i]){
                dq.pop_front();
            }
            i++;
            j++;
        }
        return ans;
        
    }
};