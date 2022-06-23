class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        int pre=0;
        
        for(int i=0;i<n;i++){
            pre=max(pre,items[i][1]);
            items[i][1]=pre;
        } 
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int low=0;
            int high=n-1;
            int temp=0;
            while(low<=high){
                int mid=(low+high)/2;
                if(items[mid][0]<=queries[i]){
                    temp=items[mid][1];
                    low=mid+1;
                }
                else if(items[mid][0]>queries[i]){
                    high=mid-1;
                }
            }
            ans.push_back(temp);
        }
    return ans;
    }
};