class Solution {
public:
    // Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
    // Output: [[1,6],[3,9],[4,5]]
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>>ans;
        for(int i=0;i<items1.size();i++){
            for(int j=0;j<items2.size();j++){
                if(items1[i][0]==items2[j][0]){
                    vector<int>temp;
                    temp.push_back(items1[i][0]);
                    temp.push_back(items1[i][1]+items2[j][1]);
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
                // else{
                //     vector<int>temp;
                //     temp.push_back(items1[i][0]);
                //     temp.push_back(items1[i][1]);
                //     vector<int>temp1;
                //     temp1.push_back(items1[j][0]);
                //     temp1.push_back(items1[j][1]);
                //     ans.push_back(temp);
                //     ans.push_back(temp1);
                //     temp.clear();
                //     temp1.clear();
                // }
            
            unordered_map<int,int>mp;
            for(int i=0;i<items1.size();i++){
                mp[items1[i][0]]++;
            }
            for(int i=0;i<items2.size();i++){
                mp[items2[i][0]]++;
            }
            cout<<mp.size()<<endl;
            for(auto x:mp){
                cout<<x.first<<" "<<x.second<<endl;
            }

            for(auto x:mp){
                for(int i=0;i<items1.size();i++){
                    if(x.second==1){
                        if(x.first==items1[i][0]){
                            ans.push_back(items1[i]);
                        }
                            // mp[x.first]++;
                    }
                }
            }
            for(auto x:mp){
                for(int i=0;i<items2.size();i++){
                    if(x.second==1){
                        if(x.first==items2[i][0]){
                            ans.push_back(items2[i]);
                        }
                            // mp[x.first]++;
                    }
                }
            }
            set<vector<int>>s;
            for(auto x:ans){
                s.insert(x);
            }
            ans.clear();
            for(auto x:s){
                ans.push_back(x);
            }
        
        return ans;
    }
};