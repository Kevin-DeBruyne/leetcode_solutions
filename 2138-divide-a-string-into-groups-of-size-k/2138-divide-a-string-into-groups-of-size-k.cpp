class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string>res;
        if(n%k==0){
            for(int i=0;i<n;i+=k){
                    string temp="";
                for(int j=i;j<i+k;j++){
                    temp.push_back(s[j]);
                }
                res.push_back(temp);
            }
        }
//         else if(n<k){
//             int less=k-n;
//             for(int i=0;i<less;i++){
//                s.push_back(fill);
//             }
//             res.push_back(s);
            

//         }
        else{
            int less=k-(n%k);
            for(int i=0;i<less;i++){
               s.push_back(fill);
        }
            for(int i=0;i<s.length();i+=k){
                    string temp="";
                for(int j=i;j<i+k;j++){
                    temp.push_back(s[j]);
                }
                res.push_back(temp);
            }
        
            // cout<<res[res.size()-1]<<endl;
        }
        return res;
    }
};