class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
        int p=0;
        int s=0;
            for(int j=1;j<=i;j++){
                p+=j;
            }
            for(int k=i;k<=n;k++){
                s+=k;
            }
            cout<<p<<" "<<s<<endl;
        if(s==p){
            return i;
        }
        }
        return -1;
    }
};