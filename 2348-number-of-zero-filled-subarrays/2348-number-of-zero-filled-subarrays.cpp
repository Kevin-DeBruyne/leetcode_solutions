class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec;
        long long temp=0;
        for(long long i=0;i<n;i++){
            if(nums[i]==0){
                temp++;
            }
            else{
                vec.push_back(temp);
                temp=0;
            }
        }
        vec.push_back(temp);
        long long ans=0;
        // for(auto x:vec){
        //     cout<<x<<" ";
        // }
        cout<<endl;
        for(long long x:vec){
            if(x==0){
                ans+=0;
            }
            else{
                ans+=x*(x+1)/2;
            }
        }
        return ans;
    }
};