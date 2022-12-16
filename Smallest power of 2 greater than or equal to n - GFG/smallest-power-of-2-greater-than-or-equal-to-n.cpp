//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long nearestPowerOf2(long long N){
        long long i=1;
        while(i<N){
            i*=2;
        }
        return i;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.nearestPowerOf2(N)<<"\n";
    }
}
// } Driver Code Ends