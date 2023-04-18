class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        stack<char>st;
        int zero=0;
        int one=0;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty() && s[i]=='1'){
                continue;
            }
            if(s[i]=='1'){
                one++;
                if(one<=zero){
                    ans=max(ans,2*one);
                }
                if(s[i+1]=='0'){
                    zero=0;
                }
            }
            else{
                one=0;
                while(!st.empty()){
                    st.pop();
                }
                st.push(s[i]);
                zero++;
            }
        }
    return ans;
    }
};