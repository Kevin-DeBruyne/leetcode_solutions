//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
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
    vector<string> permutation(string S)
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

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends