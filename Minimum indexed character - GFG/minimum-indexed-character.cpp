//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_map<char, int>mp;
        int i=0;
        for(auto x:str){
            if(mp.find(x)==mp.end()){
                mp[x]=i;
            }
        i++;
        }
        int n=str.size()+1;
        int ans=str.size()+1;
        for(auto x:patt){
            if(mp.find(x)!=mp.end()){
                ans=min(ans,mp[x]);
            }
        }
        if(ans==str.size()+1){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends