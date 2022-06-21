class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        if(maxDoubles==0){
            return target-1;
        }
        while(maxDoubles!=0){
            if(target==1){
                break;
            }
            if(target%2!=0){
                target--;
                cnt++;
                cout<<target<<endl;
            }
            else{
                target=target/2;
                cnt++;
                maxDoubles--;
                cout<<target<<endl;
            }
        }     
        if(target!=1){
            cnt+=target-1;
        }
    return cnt;
    }
};