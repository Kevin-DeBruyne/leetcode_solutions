class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0;
        int r=0;
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                r++;
            }
            else{
                l++;
            }
            if(r==l){
                cnt++;
                l=0;
                r=0;
            }
        }
        return cnt;
    }
};