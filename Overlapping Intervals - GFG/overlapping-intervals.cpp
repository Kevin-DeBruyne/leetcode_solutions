//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
         vector<vector<int>>out;
         out.push_back(intervals[0]);
        //  for(int i=1;i<intervals.size();i++){
        //      if(out[i-1][1]>intervals[i][0]){
        //          out[i-1]={out[i-1][0], max(out[i-1][1], intervals[i][1])};
        //      }
        //      else{
        //          out.push_back(intervals[i]);
        //      }
        //  }
        int j=0;
        int n=intervals.size();
         int i=1;
         while(i<n){
            //  int i=1;
             if(out[j][1]>=intervals[i][0]){
                 out[j]={out[j][0], max(out[j][1], intervals[i][1])};
             }
             else{
                 out.push_back(intervals[i]);
                j++;
                 
             }
         i++;
             
         }
         return out;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends