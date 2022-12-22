//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        vector<long long>pre;
        int temp=0;
        for(auto x:arr){
            temp+=x;
            pre.push_back(temp);
        }
        // for(auto x:pre){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        unordered_map<long long,long long>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mp.find(pre[i])!=mp.end()){
                cnt+=mp[pre[i]];
            }
            if(pre[i]==0){
                cnt++;
            }
            mp[pre[i]]++;   

        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends