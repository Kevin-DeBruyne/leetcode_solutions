class Solution {
public:
    long long digit_sum(long long n){
        long long temp=0;
        while(n!=0){
            temp+=n%10;
            n=n/10;
        }
        return temp;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long temp=n;
        if(digit_sum(n)<=target){
            return 0;
        }
        long long i=100;
        long long ans=0;
        n+=10-(n%10);
        while(digit_sum(n)>target){
            ans+=i-(n%i);
            n+=i-(n%i);
            i*=10;
        }
        ans+=10-(temp%10);
        return ans;
    }
};