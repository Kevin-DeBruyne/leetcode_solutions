class Solution {
public:
    int minOperations(int n) {
        if(n%2!=0){
            int maxi=2*(n-1)+1;
            int mid=(maxi+1)/2;
            int ans=0;
            int i=0;
            while(i<mid){
                ans+=i;
                i+=2;
            }
            return ans;
        }
        else{
            int maxi=2*(n-1)+1;
            int mid=(maxi+1)/2;
            // cout<<mid<<endl;
            int ans=0;
            int i=1;
            while(i<mid){
                ans+=i;
                i+=2;
            }
            return ans;
        }
    }
};