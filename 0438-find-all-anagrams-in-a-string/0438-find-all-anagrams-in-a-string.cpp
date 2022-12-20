class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=p.size();
        int n2=s.size();
        sort(p.begin(), p.end());
        int x=0;
        int y=n1;
        vector<int>ans;
        vector<int>v1(26);
        for(int i=0;i<p.size();i++){
            v1[p[i]-97]++;
        }
        // for(auto x:v1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        while(y<=n2){
            string temp = s.substr(x, n1);
            vector<int>v2(26);
            // cout<<temp<<endl;
            for(int i=0;i<n1;i++){
                v2[temp[i]-97]++;
            }
            if(v1==v2){
                ans.push_back(x);
            }
            v2.clear();
            x++;
            y++;
        }
        return ans;
    }
};