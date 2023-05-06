#define ll long long
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        ll n=beans.size();
        ll temp=0;
        for(int i=0;i<n;i++){
            temp+=beans[i];
        }
        ll ans=1e18;
        for(ll i=0;i<n;i++){
            ll var=(ll)(n-i)*(ll)beans[i]*1LL;
            ans=min(ans, temp-var);
        }
        return ans;
    }
};