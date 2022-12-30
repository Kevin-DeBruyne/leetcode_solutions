//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n=str1.size();
        int i=0;
        int j=2;
        bool f1=true;
        while(i<n){
            if(j>=n){
                j=j%n;
            }
            if(str1[i]!=str2[j]){
                f1=false;
                break;
            }
            i++;
            j++;
        }
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int i2=0;
        int j2=2;
        bool f2=true;
        while(i2<n){
            if(j2>=n){
                j2=j2%n;
            }
            if(str1[i2]!=str2[j2]){
                f2=false;
                break;
            }
            i2++;
            j2++;
            
        }
        if(!f1 && !f2){
            return false;
        }
        return true;
        
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends