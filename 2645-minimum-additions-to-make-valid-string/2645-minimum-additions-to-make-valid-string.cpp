class Solution {
public:
    int addMinimum(string word) {
        int i=0;
        int cnt=0;
        string s=word;
        int n=word.size();
        while(i<n){
            string s2=s.substr(i, 2);
            if(s.substr(i, 3)=="abc"){
                i+=3;
            }
            else if(s2=="ab" || s2=="ac" || s2=="bc"){
                i+=2;
                cnt+=1;
            }
            else{
                cnt+=2;
                i++;
            }
        }
        return cnt;
    }
};