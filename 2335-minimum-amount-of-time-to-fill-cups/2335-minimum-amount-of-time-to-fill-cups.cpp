class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n=amount.size();
        sort(amount.begin(),amount.end());
        int cnt=0;
        while(amount[1]!=0){
            amount[1]--;
            amount[2]--;
            cnt++;
            sort(amount.begin(),amount.end());
        }
        cnt+=amount[2];
        return cnt;
    }
};