//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({end[i], start[i]});
        }
        int cnt=1;
        int sel=0;
        sort(vec.begin(), vec.end());
        // for(auto x:vec){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(int i=1;i<n;i++){
            if(vec[i].second<=vec[sel].first){
                continue;
            }
            cnt++;
            sel=i;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends