class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        long long rem;
        vector<int>ans;
        cout<<word[0]-'0'<<endl;
        rem=(word[0]-'0')%m;
        if(rem){
            ans.push_back(0);
        }
        else{
            ans.push_back(1);
        }
        for(long long i=1;i<word.size();i++){
            rem=(rem*10+word[i]-'0')%m;
            if(rem){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }   
        }
        return ans;
    }
};