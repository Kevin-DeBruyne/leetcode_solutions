class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        set<vector<int>>res;
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i][0]]=nums1[i][1];
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i][0]]=nums2[i][1];
        }
        for(auto x:mp1){
            if(mp2.find(x.first)!=mp2.end()){
                res.insert({x.first, x.second+mp2[x.first]});
            }
            else{
                res.insert({x.first, x.second});
            }
        }
        for(auto x:mp2){
            if(mp1.find(x.first)!=mp1.end()){
                res.insert({x.first, x.second+mp1[x.first]});
            }
            else{
                res.insert({x.first, x.second});
            }
        }
        vector<vector<int>>ans;
        for(auto x:res){
            ans.push_back(x);
        }
        return ans;
    }
};