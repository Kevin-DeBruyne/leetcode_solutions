//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
	bool cmp(string& s1, string& s2){
        string t1=s1+s2;
        string t2=s2+s1;
        if(t1>t2){
            return true;
        }
        return false;
    }
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    int cnt=0;
        for(auto x:arr){
            if(x=="0"){
                cnt++;
            }
        }
        if(cnt==arr.size()){
            return "0";
        }
        sort(arr.begin(), arr.end(),cmp);
        // reverse(arr.begin(), arr.end());
        string s="";
        for(auto x:arr){
            s+=x;
        }
        
        return s;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends