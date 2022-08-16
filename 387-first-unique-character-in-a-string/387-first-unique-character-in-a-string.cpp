class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            arr[int(s[i])-97]++;
        }
        for(auto x:arr){
            cout<<x<<" ";
        }
        int cnt=0;
        for(auto x:s){
            if(arr[int(x)-97]==1){
                return cnt;
            }
            cnt++;
        }
        return -1;
    }
};