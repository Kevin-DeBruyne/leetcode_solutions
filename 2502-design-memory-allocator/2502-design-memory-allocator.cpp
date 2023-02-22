class Allocator {
public:
    vector<int>vec;
    Allocator(int n) {
        vec.resize(n,1001);
    }
    
    int allocate(int size, int mID) {
        if(size==1){
            int i;
            for(i=0;i<vec.size();i++){
                if(vec[i]==1001){
                    vec[i]=mID;
                    break;
                }
            }
            if(i>=vec.size()){
            return -1;
        }
            return i;
        }
        int t=1;
        int ind=0;
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i+1]==1001 && vec[i]==1001){
                t++;
                if(t==size){
                    break;
                }
            }
            else{
                t=1;
                ind=i+1;
            }
        }
        
        if(t>=size){
            for(int i=ind;i<ind+t;i++){
                vec[i]=mID;
            }
            
        return ind;
        }
        else{
            return -1;
        }
        // for(auto x:vec){
        //     cout<<x<<" ";
        // }
    }
    
    int free(int mID) {
        int res=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==mID){
                res++;
                vec[i]=1001;
            }
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */