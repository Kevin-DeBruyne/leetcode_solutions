class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n=changed.size();
        if(n==1){
            return {};
        }
        unordered_map<int, int>mp;
        sort(changed.begin(), changed.end());
        for(auto x:changed){
            mp[x]++;
        }
        vector<int>vec;
        for(int i=0;i<n;i++){
            // cout<<mp[changed[i]]<<endl;
            if(mp[changed[i]]==0){
                // cout<<"if hu"<<endl;
                // i++;
                continue;
            }
            else{
                // cout<<mp[changed[i]]<<" "<<mp[changed[i]*2]<<endl;
            // cout<<i<<endl;
                if(!mp.count(changed[i]*2)){
                    // cout<<"kyu"<<endl;
                    return {};
                }
                else{
                    vec.push_back(changed[i]);
                    mp[changed[i]]--;
                    mp[changed[i]*2]--;
                    if(mp[changed[i]]<0 ){
                        return {};
                    }
                    if(mp[changed[i]]*2<0 ){
                        return {};
                    }
                }
            }
        }
        return vec;
    }
};