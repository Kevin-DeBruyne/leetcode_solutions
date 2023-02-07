class DataStream {
public:
    int val;int cnt;int size;
    DataStream(int value, int k) {
        val=value;
        cnt=0;
        size=k;
    }
    
    bool consec(int num) {
        if(num==val){
            cnt++;
        }
        else{
            cnt=0;
        }
        if(cnt>=size){
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */