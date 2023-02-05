class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0;
        unordered_set<int>st;
        for(auto x:banned){
            st.insert(x);
        }
        vector<int>vec;
        int i=1;
        while(i<=n && sum<=maxSum){
            if(st.find(i)==st.end()){
                sum+=i;
                vec.push_back(i);
            }
            i++;
        }
        if(sum>maxSum){
            sum-=i-1;
            vec.pop_back();
        }
        // for(auto x:vec){
        //     cout<<x<<" ";
        // }
        // cout<<sum<<endl;
        return vec.size();
    }
};