class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int a=piles.size()-1;
        int m=piles.size()-2;
        int b=0;
        int ans=0;
        while(m>b){
            ans+=piles[m];
            b++;
            a-=2;
            m-=2;
        }
        return ans;
    }
};