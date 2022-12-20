class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        sort(s1.begin(), s1.end());
        int x=0;
        int y=n1;
        vector<int>v1(26);
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-97]++;
        }
        // for(auto x:v1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        while(y<=n2){
            string temp = s2.substr(x, n1);
            vector<int>v2(26);
            // cout<<temp<<endl;
            for(int i=0;i<n1;i++){
                v2[temp[i]-97]++;
            }
            if(v1==v2){
                return true;
            }
            v2.clear();
            x++;
            y++;
        }
        return false;
    }
};