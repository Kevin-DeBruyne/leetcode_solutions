//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int ans=0;
            int res;
            for(int i=0;i<N;i++){
                int temp=0;
                auto it=lower_bound(Mat[i].begin(), Mat[i].end(), 1);
                temp=M-(it-Mat[i].begin());
                if(temp>ans){
                    res=i;
                    ans=temp;
                }
                // ans=max(ans, temp);
                // cout<<endl;
            }
        return res;
            
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends