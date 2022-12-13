class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int n=temperatures.size();
        // unordered_map<int,int>mp;
        // for(int i=0;i<n;i++){
        //     mp[temperatures[i]]=i;
        // }
        vector<int>ans(n);
        int i=0;
        while(i<n){
            if(st.empty() || temperatures[i]<=st.top().first){
                st.push(make_pair(temperatures[i],i));
            }
            else{
                while(!st.empty() && temperatures[i]>st.top().first){
                    ans[st.top().second]=i-st.top().second;
                    st.pop();
                }
                    st.push(make_pair(temperatures[i],i));
            }
            // mp[temperatures[i]]=i;
            i++;
        }
        while(!st.empty()){
            ans[st.top().second]=0;
            st.pop();
        }
        
        return ans;
    }
};