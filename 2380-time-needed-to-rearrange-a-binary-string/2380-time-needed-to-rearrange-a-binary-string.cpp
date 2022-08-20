class Solution {
public:
    bool check(string& s){
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i-1]=='0' && s[i]=='1'){
                return false;
            }
            
        }
        return true;
    }
    int secondsToRemoveOccurrences(string s) {
        int cnt=0;
        int n=s.size();
        if(check(s)){
            return 0;
        }
        while(!check(s)){
            // cout<<"yes"<<endl;
            cnt++;
            for(int i=1;i<n;i++){
                if(s[i-1]=='0' && s[i]=='1'){
                    // cout<<"yes"<<endl;
                    swap(s[i-1],s[i]);
                    i++;
                }   
            }
            // cout<<s<<endl;
            
        }
        // cout<<s<<endl;
//         swap(s[0], s[s.size()-1]);
//         cout<<s<<endl;
        
        return cnt;
    }
};