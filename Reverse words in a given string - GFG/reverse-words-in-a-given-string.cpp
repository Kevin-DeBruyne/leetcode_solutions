//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string>st;
        string temp="";
        for(auto x:S){
            if(x=='.'){
                st.push(temp);
                temp.clear();
            }
            else{
                temp+=x;
            }
        }
        st.push(temp);
        string ans="";
        while(!st.empty()){
            // cout<<st.top()<<endl;
            ans+=st.top();
            ans+='.';
            st.pop();
        }
        // cout<<endl;
        ans.pop_back();
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends