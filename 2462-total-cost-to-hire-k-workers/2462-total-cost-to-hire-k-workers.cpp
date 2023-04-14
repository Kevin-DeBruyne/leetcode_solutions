#define ll long long
class Solution
{
    public:
        long long totalCost(vector<int> &costs, int k, int candidates)
        {
            priority_queue<ll, vector < ll>, greater < ll>> pq;
            priority_queue<ll, vector < ll>, greater < ll>> first;
            priority_queue<ll, vector < ll>, greater < ll>> last;
            ll cnt = 0;
            ll now=0;
            if(candidates*2<costs.size()){
                for(ll i=0;i<candidates;i++){
                    // cout<<costs[i]<<" ";
                    first.push(costs[i]);
                }
                cout<<endl;
                for(ll i=costs.size()-candidates;i<costs.size();i++){
                    // cout<<costs[i]<<" ";
                    last.push(costs[i]);
                }
                ll i=candidates;
                ll j=costs.size()-candidates-1;
                // cout<<costs[i]<<" "<<costs[j]<<endl;
                ll ans=0;
                ll noc=costs.size();
                ll count=0;
                while(candidates*2<noc && count<k){
                    if(first.top()<=last.top()){
                        // cout<<"first"<<"="<<first.top()<<endl;
                        ans+=first.top();
                        first.pop();
                        first.push(costs[i]);
                        i++;
                    }
                    else{
                        // cout<<"last"<<"="<<last.top()<<endl;
                        ans+=last.top();
                        last.pop();
                        last.push(costs[j]);
                        j--;
                    }
                noc--;
                count++;
                }
                cout<<count<<endl;
                priority_queue<ll, vector < ll>, greater < ll>> temp;                             while(!first.empty()){
                    temp.push(first.top());
                    first.pop();
                }
                while(!last.empty()){
                    temp.push(last.top());
                    last.pop();
                }
                while(count<k){
                    ans+=temp.top();
                    count++;
                    temp.pop();
                }
                // cout<<count<<" "<<k<<endl;
                return ans;
            }
            else{
                for(auto x:costs){
                    pq.push(x);
                }
                ll cnt=0;
                ll ans=0;
                while(cnt<k){
                    ans+=pq.top();
                    pq.pop();
                    cnt++;
                }
                return ans;
            }
        }
};