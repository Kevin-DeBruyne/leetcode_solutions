//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends


string printSequence(string S)
{
    vector<string>vec{"2", "22", "222","3", "33", "333","4", "44", "444","5", "55", "555", "6", "66", "666",
        "7", "77", "777","7777","8", "88", "888","9", "99", "999","9999"};
        string ans="";
        for(auto x:S){
            if(x==' '){
                ans.push_back('0');
            }
            ans+=vec[int(x)-65];
        }
        return ans;
}
