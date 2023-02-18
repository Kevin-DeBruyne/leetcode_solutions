class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> pums=nums;
        vector<int> gums=nums;
        int n=nums.size();
        nums[0]=nums[2];
        nums[1]=nums[2];
        sort(nums.begin(), nums.end());
        int a=nums[nums.size()-1]-nums[0];
        int score1=a;
        
        pums[n-1]=pums[n-3];
        pums[n-2]=pums[n-3];
        sort(pums.begin(), pums.end());
        int a1=pums[pums.size()-1]-pums[0];
        int score2=a1;
        
        gums[0]=gums[1];
        gums[n-1]=gums[n-2];
        sort(gums.begin(), gums.end());
        int a3=gums[gums.size()-1]-gums[0];
        int b3=gums[1]-gums[0];
        int score3=a3+b3;
        cout<<score1<<" "<<score2<<" "<<score3<<endl;
        int res=min(score1, score2);
        
        return min(res, score3);
    }
};