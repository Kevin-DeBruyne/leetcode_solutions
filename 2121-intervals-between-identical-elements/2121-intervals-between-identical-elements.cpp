#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) 
{
        map<ll, vector<ll>> mp;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]].size()==0){
                mp[arr[i]].push_back(i);
            }
            else{
                ll yt=mp[arr[i]][mp[arr[i]].size()-1]+i;
                mp[arr[i]].push_back(yt);
            }
        }
        // for(auto x:mp){
        //     cout<<x.first<<"->";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        unordered_map<int,int>freq;
        vector<ll>res;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            ll fn=freq[arr[i]];
            auto &temp=mp[arr[i]];
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