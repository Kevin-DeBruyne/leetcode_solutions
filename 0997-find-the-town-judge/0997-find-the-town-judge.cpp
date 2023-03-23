class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        cout<<trust.size()<<endl;
        if(trust.size()==0 && n==1){
            return 1;
        }
        else if(trust.size()==0 && n>1){
            return -1;
        }
        unordered_set<int>st;
        for(auto x:trust){
            st.insert(x[0]);
        }
        if(st.size()==n){
            return -1;
        }
        int t;
        t=trust[0][1];
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][1]]++;
        }
        for(auto x:mp){
            if(x.second==n-1){
                return x.first;
            }
        }
        return -1;
    }
};