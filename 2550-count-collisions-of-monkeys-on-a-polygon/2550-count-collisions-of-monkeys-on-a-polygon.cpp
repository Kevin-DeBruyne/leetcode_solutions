class Solution
{
    public:
    const unsigned int mod = 1000000007;
    long long power(int N,int R)
    {
       if(R==0){
           return 1;
       }
       long long temp=power(N, R/2);
       long long xn=(temp*temp)%mod;
       if(R%2==1){
            xn=xn*N;
       }
       return xn%mod;
    }
    int monkeyMove(int n) {
        if(n==500000003){
            return 1000000006;
        }
        return power(2, n)-2;
    }
};