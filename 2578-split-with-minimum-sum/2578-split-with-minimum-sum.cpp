class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        sort(s.begin(), s.end());
        string s1="";
        string s2="";
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                s1+=s[i];
            }
            else{
                s2+=s[i];
            }
        }
        int n1=stoi(s1);
        int n2=stoi(s2);
        cout<<s1<<" "<<s2<<endl;
        return n1+n2;
    }
};