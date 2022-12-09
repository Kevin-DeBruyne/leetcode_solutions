//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>>stockBuySell(vector<int> A, int n){
        vector<int>B=A;
        reverse(B.begin(), B.end());
        if(is_sorted(B.begin(), B.end())){
            return {};
        }
        stack<int>st;
        int start=0;
        int end;
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(A[i]);
                start=i;
            }
            else if(A[i]>st.top()){
                st.push(A[i]);
            }
            else{
                end=i-1;
                // if(start!=end){
                    vec.push_back({start, end});
                // }
                while(!st.empty()){
                    st.pop();
                }
                
                st.push(A[i]);
                start=i;
            }
        }
        end=n-1;
        vec.push_back({start, end});
        // cout<<st.top()<<endl;
        // for(auto x:vec){
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        return vec;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends