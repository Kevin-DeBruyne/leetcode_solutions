//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
        set<vector<int>>ans;
	    void help(vector<int> que, vector<int> asf){
	        int n=que.size();
	        if(que.size()==0){
	            ans.insert(asf);
	            return;
	        }
	        for(int i=0;i<que.size();i++){
	            vector<int>roq;
	            int ch=que[i];
	            for(int j=0;j<que.size();j++){
	                if(j!=i){
	                    roq.push_back(que[j]);
	                }
	            }
	            vector<int>temp=asf;
	            temp.push_back(ch);
	            help(roq, temp);
	        }   
	    }
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
            vector<int>asf;
            sort(arr.begin(), arr.end());
            help(arr,asf);
            vector<vector<int>>res;
            // cout<<ans.size()<<endl;
            for(auto x:ans){
                res.push_back(x);
            }
            return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends