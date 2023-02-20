class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int>mp;
        vector<int>vec;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int len=1;
        int end=INT_MIN;
        cout<<end;
        for(int i=0;i<s.size();i++){
            end=max(end, mp[s[i]]);
            if(i==end){
                vec.push_back(len);
                len=1;
            }
            else{
                len++;
            }
        }
        // vec.push_back(len);
        return vec;
    }
};