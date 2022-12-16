//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int i=0;
        int j=k-1;
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        if(k==1){
            return temp;
        }
        // int n=arr.size();
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(arr[i]);            
        }
        ans.push_back(dq.front());
        if(dq.front()==arr[i]){
                dq.pop_front();
        }
        i++;
        j++;
        while(j<n){
            while(!dq.empty() && arr[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            ans.push_back(dq.front());
            if(dq.front()==arr[i]){
                dq.pop_front();
            }
            i++;
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends