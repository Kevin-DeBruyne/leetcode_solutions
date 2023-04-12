class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int nox=0;
        int noy=0;
        if(s1==s2){
            return 0;
        }
        for(auto i:s1){
            if(i=='x'){
                nox++;
            }
            else{
                noy++;
            }
        }
        for(auto i:s2){
            if(i=='x'){
                nox++;
            }
            else{
                noy++;
            }
        }
        if(nox%2!=0 || noy%2!=0){
            return -1;
        }
        int i=0;
        while(i<s1.size()){
            if(s1[i]==s2[i]){
                s1.erase(i,1);
                s2.erase(i,1);
            }
            else{
                i++;
            }
        }
        int xs1=0;
        for(auto i:s1){
            if(i=='x'){
                xs1++;
            }
        }
        cout<<s1<<" "<<s2<<endl;
        int ans=0;
        int temp=s1.size()/2;
        if(xs1%2==0){
            ans+=temp;
            cout<<"NO"<<endl;
        }
        else{
            cout<<"yes"<<endl;
            ans+=temp-1;
            ans+=2;        
        }
        return ans;
    }
};