class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>subset;
        map<char,int>set;
        for(int i=0;i<words2.size();i++){
            map<char,int>temp;
            for(int j=0;j<words2[i].size();j++){
                temp[words2[i][j]]++;
            }
            for(auto x:temp){
                subset[x.first]=max(x.second, subset[x.first]);
            }
        }
        vector<string>res;
        for(int i=0;i<words1.size();i++){
            set.clear();
            for(int j=0;j<words1[i].size();j++){
                set[words1[i][j]]++;
            }
            int flag=1;
            for(auto x:subset){
                // cout<<x.first<< ": "<<set[x.first]<<" "<<subset[x.first]<<endl;
                if(set[x.first]<subset[x.first]){
                    // cout<<"fail"<<endl;
                    flag=0;
                }
                // else{
                //      cout<<"pass"<<endl;
                // }
            }
            if(flag){
                res.push_back(words1[i]);
            }
            else{
                continue;
            }
        }
        
        return res;
    }
};