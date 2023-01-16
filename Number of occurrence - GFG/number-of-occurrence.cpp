//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int l1=0;
	    int h1=n-1;
	    bool is=false;
	    while(l1<=h1){
	        int mid1=(l1+h1)/2;
	        if(x==arr[mid1]){
	            is=true;
	            break;
	        }
	        if(x>arr[mid1]){
	            l1=mid1+1;
	        }
	        else{
	            h1=mid1-1;
	        }
	    }
	    if(is){
	        int l2=0;
	        int h2=n-1;
	        int first;
	        while(l2<=h2){
	            int mid2=(l2+h2)/2;
	            if(x==arr[mid2]){
	                if(arr[mid2]!=arr[mid2-1]){
	                    first=mid2;
	                    break;
	                }
	                else{
	                    h2=mid2-1;
	                }
	                
	            }
	            if(x>arr[mid2]){
	                l2=mid2+1;
	            }
	            else{
	                h2=mid2-1;
	            }
	        }
	        int l3=0;
	        int h3=n-1;
	        int last=-10;
	        while(l3<=h3){
	            int mid3=(l3+h3)/2;
	            if(x==arr[mid3]){
	                if(mid3==n-1){
	                    last=n-1;
	                    break;
	                }
	                if(arr[mid3]!=arr[mid3+1]){
	                    last=mid3;
	                    break;
	                }
	                else{
	                    l3=mid3+1;
	                }
	                
	            }
	            else if(x>arr[mid3]){
	                l3=mid3+1;
	            }
	            else{
	                h3=mid3-1;
	            }
	        }
	       // cout<<first<<" "<<last<<endl;
	        return last-first+1;
	    }
	    else{
	        return 0;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends