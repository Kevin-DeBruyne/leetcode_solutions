class Solution {
public:
    string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string stom(string s){
        string temp;
        for(int i=0;i<s.size();i++){
            temp+=arr[s[i]-97];
        }
        return temp;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>st;
        for(int i=0;i<words.size();i++){
            st.insert(stom(words[i]));
        }
        return st.size();
    }
};