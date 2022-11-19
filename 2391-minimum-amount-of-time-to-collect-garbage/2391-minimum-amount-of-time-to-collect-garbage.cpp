class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int>mp;
        int n=garbage.size();
        int g,p,m;
        g=0;p=0;m=0;
        vector<int>pre;
        int temp=0;
        // pre.insert(pre.begin(), 6);
        for(auto x:travel){
            temp+=x;
            pre.push_back(temp);
        }
        for(auto x:pre){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].size();j++){
                mp[garbage[i][j]]=i;    
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='G'){
                    g++;
                }
                else if(garbage[i][j]=='P'){
                    p++;
                }
                else if(garbage[i][j]=='M'){
                    m++;
                }
            }
        }
        // cout<<g<<" "<<p<<" "<<m<<endl;
        for(auto x:mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        int ans=0;
        ans=g+p+m;
        if(g!=0){
            if(mp['G']!=0){
                ans+=pre[mp['G']-1];
            }
        }
        if(p!=0){
            if(mp['P']!=0){
                ans+=pre[mp['P']-1];
            }
            
        }
        if(m!=0){
            if(mp['M']!=0){
                ans+=pre[mp['M']-1];
            }
        }
        // cout<<pre[mp['M']-1]<<" "<<pre[mp['G']-1]<<endl;
        
        
        return ans;
    }
};