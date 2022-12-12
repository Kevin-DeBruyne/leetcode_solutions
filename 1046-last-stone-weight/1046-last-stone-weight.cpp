class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(!pq.empty() && pq.size()!=1){
            
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            cout<<y<<" "<<x<<endl;
            if(x!=y){
                pq.push(y-x);
            }
        }
        if(pq.empty()){
            return 0;
        }
        else{
            int ans=pq.top();
            return ans;
        }
        
    }
};