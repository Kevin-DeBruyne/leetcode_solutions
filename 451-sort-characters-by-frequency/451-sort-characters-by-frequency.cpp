class Solution {
public:
    // static bool mycomp(pair<int, char>a, pair<int, char>b){
    //     return a.second>b.second;
    // }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto x:s){
            if(int(x)<97){
                mp[x]++;
            }
            else{
                mp[x]++;
                
            }
        }
        for(auto x:mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        // cout<<endl;
        vector<pair<int,char>>vec;
        int n=mp.size();
        for(auto x:mp){
            vec.push_back(make_pair(x.second, x.first));
        }
        // cout<<vec.size()<<endl;
        sort(vec.rbegin(), vec.rend());
        for(auto x:vec){
            if(x.first==0){
                break;
            }
            cout<<x.first<<" "<<x.second<<endl;
        }
        string ans="";
        // sort(vec.begin(), vec.end(), mycomp);
        for(auto x:vec){
            if(x.first==0){
                break;
            }
            for(int i=0;i<x.first;i++){
                ans+=x.second;
            }
        }
        return ans;
    }
};