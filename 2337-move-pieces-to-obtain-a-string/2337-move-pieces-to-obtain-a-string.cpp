class Solution {
public:
    bool canChange(string start, string target) {
        int a=0;
        int b=0;
        for(auto x:start){
            if(x!='_'){
                a++;
            }
        }
        for(auto x:target){
            if(x!='_'){
                b++;
            }
        }
        if(a!=b){
            return false;
        }
        int i=0;
        int j=0;
        int n=start.size();
        while(i<n && j<n){
            if(start[i]=='_' && target[j]=='_'){
                i++;
                j++;
            }
            else if(start[i]=='_' && target[j]!='_'){
                i++;
            }
            else if(start[i]!='_' && target[j]=='_'){
                j++;
            }
            else{
                if(start[i]=='L' && target[j]=='R' || start[i]=='R' && target[j]=='L'){
                    cout<<"1";
                    // cout<<"1";
                    return false;
                }
                else if(start[i]=='L' && target[j]=='L' && j>i){
                    cout<<"2";
                    return false;
                }
                else if(start[i]=='R' && target[j]=='R' && j<i){
                    cout<<"3";
                    return false;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        cout<<start.size()<<" "<<target.size()<<endl;
        return true;
    }
};