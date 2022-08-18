class Solution {
public:
    static bool sortby(const pair<int,int> &a,
                   const pair<int,int> &b)
    {
        if(a.first<b.first){
            return true;
        }
        if(a.first==b.first){
            return a.second>b.second;
        }
        return false;
        
        
    }
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(auto x:nums){
           mp[x]++;
                
        }
        // cout<<endl;
        vector<pair<int,int>>vec;
        int n=mp.size();
        for(auto x:mp){
            vec.push_back(make_pair(x.second, x.first));
        }
        // cout<<vec.size()<<endl;
        sort(vec.begin(), vec.end(),sortby);
        for(auto x:vec){
            cout<<x.first<<" "<<x.second<<endl;
        }
        // cout<<endl;
        vector<int>ans;
        for(auto x:vec){
            for(int i=0;i<x.first;i++)
                ans.push_back(x.second);
        }
        
        return ans;
    }
    
};