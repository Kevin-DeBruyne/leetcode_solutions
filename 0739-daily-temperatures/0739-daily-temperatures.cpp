class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans(n);
        int i=0;
        while(i<n){
            if(st.empty() || temperatures[i]<=temperatures[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                    st.push(i);
            }
            i++;
        }
        while(!st.empty()){
            ans[st.top()]=0;
            st.pop();
        }
        
        return ans;
    }
};