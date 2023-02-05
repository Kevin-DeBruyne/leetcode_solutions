class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>res;
        vector<string>vec;
        for(int i=nums.size()-1;i>=0;i--){
            int n=nums[i];
            while(n!=0){
                res.push_back(n%10);
                n=n/10;
            }
        }
            reverse(res.begin(), res.end());
        
        return res;
    }
};