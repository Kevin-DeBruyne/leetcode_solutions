class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(), temp.end());
        int ans=0;
        int ind=0;
        for(int i=0;i<nums.size();i++){
            auto ub=upper_bound(temp.begin()+ind+1, temp.end(), temp[i]);
            if(ub!=temp.end()){
                ans++;
                ind=ub-temp.begin();
                    
                // temp.erase(temp.begin()+ind);
            }
        }
        return ans;
    }
};