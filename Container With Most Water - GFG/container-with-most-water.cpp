//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    int l=0;
    int r=len-1;
    long long maxi=0;
    while(l<r){
        long long vol=min(A[l], A[r])*(r-l);
        maxi=max(vol, maxi);
        if(A[l]>A[r]){
            r--;
        }
        else{
            l++;
        }
    }
    return maxi;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends