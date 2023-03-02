class Solution {
public:
    bool isEmp(priority_queue<pair<int, char>> pq){
        int s=pq.size();
        int cnt=0;
        while(!pq.empty()){
            if(pq.top().first==0){
                cnt++;
            }
            pq.pop();
        }
        if(cnt==s){
            return true;
        }
        return false;
    }
    string reorganizeString(string s) {
        map<char, int>mp;
        for(auto x:s){
            mp[x]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto x:mp){
            pq.push(make_pair(x.second, x.first));
        }
        string ans="";
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
         while(pq.size()>1){
            auto top1= pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            ans+=top1.second;
            ans+=top2.second;
            
            top1.first -=1;
            top2.first -= 1;
            
            if(top1.first > 0)
                pq.push(top1);
            
            if(top2.first > 0)
                pq.push(top2);
        }
        if(ans.size()==s.size()){
            return ans;
        }
        if(pq.top().first>1){
            return "";
        }
        else{
            ans+=pq.top().second;
        }
        return ans;
    }
};