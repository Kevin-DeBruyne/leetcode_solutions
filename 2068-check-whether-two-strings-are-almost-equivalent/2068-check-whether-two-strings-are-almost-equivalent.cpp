class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        unordered_set<char>st1;
        unordered_set<char>st2;
        int n=word1.length();
        int m=word2.length();
        for(int i=0;i<n;i++){
            mp1[word1[i]]++;
            st1.insert(word1[i]);
        }
        for(int i=0;i<m;i++){
            mp2[word2[i]]++;
            st2.insert(word2[i]);
        }
        for(auto x:st1){
            if(abs(mp1[x]-mp2[x])>3){
                return false;
            }
        }
        for(auto x:st2){
            if(abs(mp1[x]-mp2[x])>3){
                return false;
            }
        }
        return true;
        }
    
};