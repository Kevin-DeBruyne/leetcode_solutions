class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        cout<<n<<endl;
        vector<int>pre;
        int temp=0;
        for(int i=0;i<n;i++){
            if(blocks[i]=='B'){
                temp++;
            }
            pre.push_back(temp);
        }
        for(auto x:pre){
            cout<<x<<" ";
        }
        cout<<endl;
        int i=1, j=k;
        int ans=INT_MAX;
        ans=k-(pre[k-1]);
        int tempo=ans;
        if(tempo<=0){
            return 0;
        }
        cout<<ans<<endl;
        while(j<n){
            ans=min(ans, k-(pre[j]-pre[i-1]));    
            cout<<ans<<endl;
            
            j++;
            i++;
            }
        return ans;
        
    }
};