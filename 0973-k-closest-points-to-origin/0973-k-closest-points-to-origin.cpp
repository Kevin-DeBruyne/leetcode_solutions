class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>>pq;
        for(int i=0;i<points.size();i++){
            int dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push_back({dis, points[i]});
        }
        sort(pq.begin(), pq.end());
        int i=0;
        vector<vector<int>>ans;
        while(i<k){
            ans.push_back(pq[i].second);
            i++;
        }
        return ans;
    }
};