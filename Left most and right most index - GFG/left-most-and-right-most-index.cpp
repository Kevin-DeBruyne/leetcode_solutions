//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int n=v.size();
        int l1=0;
	    int h1=n-1;
	    bool is=false;
	    while(l1<=h1){
	        int mid1=(l1+h1)/2;
	        if(x==v[mid1]){
	            is=true;
	            break;
	        }
	        if(x>v[mid1]){
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
	            if(x==v[mid2]){
	                if(v[mid2]!=v[mid2-1]){
	                    first=mid2;
	                    break;
	                }
	                else{
	                    h2=mid2-1;
	                }
	                
	            }
	            if(x>v[mid2]){
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
                if(v[mid3]>x){
                    h3=mid3-1;
                }
                else if(v[mid3]<x){
                    l3=mid3+1;
                }
                else{
                    if(mid3==n-1 || v[mid3]!=v[mid3+1]){
                        last=mid3;
                        break;
                }
                else{
                    l3=mid3+1;
                }
            }
	        }
	       // cout<<first<<" "<<last<<endl;
	        return {first, last};
	    }
	    else{
	        return {-1,-1};
	    }
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends