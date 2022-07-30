class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        // vector<string>vec;
        int i=0;
        while(i<s.length()){
            string temp="";
            if(int(s[i])==32){
                temp="";
                i++;
            }
            else{
                while(int(s[i])!=32 && i<s.length()){
                    temp+=s[i];
                    i++;
                }
            st.push(temp);
            // vec.push_back(temp);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=" ";
            }
        }
        return ans;
    }
};