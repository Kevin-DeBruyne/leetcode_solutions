//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>solve(string s){
	    if(s.length()==0){
		        vector<string>ans;
		        ans.push_back("");
		        return ans;
		    }
		    char c=s[0];
		    string temp=s.substr(1);
		    vector<string>a=solve(temp);
		    vector<string>ans;
		    for(int i=0;i<a.size();i++){
		        ans.push_back(a[i]);
		        ans.push_back(c+a[i]);
		    }
		    return ans;
	}
		vector<string> AllPossibleStrings(string s){
		    vector<string>x=solve(s);
		    sort(x.begin(),x.end());
		    x.erase(x.begin());
		    return x;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends