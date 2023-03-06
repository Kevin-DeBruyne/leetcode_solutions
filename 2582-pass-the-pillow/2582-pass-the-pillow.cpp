class Solution {
public:
    int passThePillow(int n, int time) {
        int ind=1;
        int dir=1;
        while(time){
            ind+=dir;
            if(ind==1){
                dir=dir*-1;
            }
            if(ind==n){
                dir=dir*-1;
            }
            time--;
        }
        return ind;
    }
};