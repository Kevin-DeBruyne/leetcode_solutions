class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2!=0){
            return {};
        }
        sort(changed.begin(), changed.end());
        unordered_map<int, int>mp;
        for(auto x:changed){
            mp[x]++;
        }
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0){
                continue;
            }
            else{
                if(!mp.count(changed[i]*2)){
                    return {};
                }
                else{
                    vec.push_back(changed[i]);
                    mp[changed[i]]--;
                    mp[changed[i]*2]--;
                    if(mp[changed[i]]<0){
                        return {};
                    }
                    if(mp[changed[i]*2]<0){
                        return {};
                    }
                }
            }
        }
        return vec;
    }
};