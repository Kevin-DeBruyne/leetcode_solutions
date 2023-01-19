//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void help(vector<string>&ans, string que, string asf){
	        int n=que.size();
	        if(que.size()==0){
	            ans.push_back(asf);
	            return;
	        }
	        for(int i=0;i<que.size();i++){
	            char ch=que[i];
	            string left=que.substr(0, i);
	            string right=que.substr(i+1, n-(i));
	            string roq=left+right;
	            help(ans, roq, asf+ch);
	        }   
	    }
	    vector<string>find_permutation(string S)
		{
		    vector<string>ans;
            help(ans, S, "");
            set<string>st;
            for(auto x:ans){
                st.insert(x);
            }
            vector<string>res;
            for(auto x:st){
                res.push_back(x);
            }
            return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends