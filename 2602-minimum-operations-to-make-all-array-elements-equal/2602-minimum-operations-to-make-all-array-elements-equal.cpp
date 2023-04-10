#define ll long long
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long>ans;
        sort(nums.begin(), nums.end());
        vector<long long>pre;
        long long temp=0;
        for(auto x:nums){
            temp+=x;
            pre.push_back(temp);
        }
        for(int i=0;i<queries.size();i++){
            long long q=queries[i];
            long long res=0;
            ll upper = upper_bound(nums.begin(), nums.end(), queries[i])-nums.begin();
            ll small=upper;
            ll large=nums.size()-small;
            if(small!=0){
            ans.push_back(small*queries[i]-pre[small-1]+temp-pre[small-1]-large*queries[i]);
            }
            else{
                ans.push_back(temp-large*queries[i]);
            }
        }
    return ans;
    }
};