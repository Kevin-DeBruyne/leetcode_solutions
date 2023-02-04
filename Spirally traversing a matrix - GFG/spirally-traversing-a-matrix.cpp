//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>res;
        int d=1;int l=0;int t=0;int b=r;
        // c--;
        while(l<c && t<b){
            if(d==1){
                for(int i=l;i<c;i++){
                    res.push_back(matrix[t][i]);
                }
                    t++;
                    d=2;
            }
            else if(d==2){
                for(int i=t;i<b;i++){
                    res.push_back(matrix[i][c-1]);
                }
                    c--;
                    d=3;
            }
            else if(d==3){
                for(int i=c-1;i>=l;i--){
                    res.push_back(matrix[b-1][i]);
                }
                    b--;
                    d=4;
            
            }
            else if(d==4){
                for(int i=b-1;i>=t;i--){
                    res.push_back(matrix[i][l]);
                }
                    l++;
                    d=1;
            
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends