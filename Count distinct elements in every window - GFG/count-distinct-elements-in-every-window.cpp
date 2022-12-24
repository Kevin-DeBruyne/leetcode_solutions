//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int>vec;
        unordered_map<int,int>st;
        int i=0;
        int j=k-1;
        for(int i=0;i<k;i++){
            st[A[i]]++;
        }
        while(j<n){
            vec.push_back(st.size());
            st[A[i]]--;
            if(st[A[i]]==0){
                st.erase(A[i]);
            }
            i++;
            j++;
            st[A[j]]++;
        }
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends