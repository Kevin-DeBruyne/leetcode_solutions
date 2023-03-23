#define PII pair<int, int>
class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int mini;
        priority_queue<PII, vector<PII>, Compare>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
        }
        unordered_map<int, bool>mp;
        for(int i=0;i<nums.size();i++){
            mp[i]=true;
        }
        while(!pq.empty()){
            mini=INT_MAX;
            int ind;
            int n=nums.size();
            if(mp[pq.top().second]){
                mini=min(mini, pq.top().first);
                ind=pq.top().second;
                ans+=mini;
                pq.pop();
            }
            else{
                pq.pop();
                continue;
            }
            if(ind==0 && n>1){
                mp[ind]=false;
                mp[ind+1]=false;
            }
            else if(ind==n-1 && n>1){
                mp[ind]=false;
                mp[ind-1]=false;
            }
            else if(n==1){
                return ans;
            }
            else{
                mp[ind]=false;
                mp[ind+1]=false;
                mp[ind-1]=false;
            }
        }
    return ans;
    }
};