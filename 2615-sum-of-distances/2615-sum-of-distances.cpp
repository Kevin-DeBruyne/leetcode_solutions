#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<ll, vector<ll>> mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]].size()==0){
                mp[nums[i]].push_back(i);
            }
            else{
                ll yt=mp[nums[i]][mp[nums[i]].size()-1]+i;
                mp[nums[i]].push_back(yt);
            }
        }
        unordered_map<int,int>freq;
        vector<ll>res;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            ll fn=freq[nums[i]];
            auto &temp=mp[nums[i]];
            if(temp.size()>1){
                if(fn==1){
                   res.push_back(temp[temp.size()-1]-temp.size()*i); 
                }
                else{
                    res.push_back((fn-1)*i-temp[fn-2]+temp[temp.size()-1]-temp[fn-1]-(temp.size()-fn)*i);
                }
            }
            else{
                res.push_back(0);
            }
        }
        return res;
    }
};