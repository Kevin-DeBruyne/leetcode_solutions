class Solution {
public:
     long long DigitSum(long long n) {
        long long res = 0;
        while (n) {
            int rem = n % 10;
            res += rem;
            n /= 10;
        }
        return res;
    }
    long long maximumSum(vector<int>& nums) {
        priority_queue<long long>arr[82];
        for(auto x:nums){
            arr[DigitSum(x)].push(x);
        }
        long long res=INT_MIN;
        // int sum=0;
        int flag=0;
        for(auto i:arr){
            long long sum=0;
            if(i.size()>1){
                flag=1;
                sum+=i.top();
                i.pop();
                sum+=i.top();
                cout<<sum<<endl;
            }
            
            res=max(res,sum);
        }
        if(!flag){
            return -1;
        }
        return res;
    }
    
};