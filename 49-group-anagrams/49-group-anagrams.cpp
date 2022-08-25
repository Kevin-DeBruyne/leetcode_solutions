class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        vector<vector<string>>vec;
        for(auto x:mp){
            vec.push_back(x.second);
        }
        return vec;
    }
};