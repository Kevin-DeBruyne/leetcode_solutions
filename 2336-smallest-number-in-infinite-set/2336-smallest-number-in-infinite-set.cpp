class SmallestInfiniteSet {
public:
    vector<int> mp;
    SmallestInfiniteSet() {
        mp.resize(1001,1);
    }
    
    int popSmallest() {
        // for(auto x:mp){
        //     if(x==true){
        //         int temp;
        //         temp=x.first;
        //         mp[x.first]=false;
        //         break;
        //     }
        // }
        int i;
        for(i=1;i<=1000;i++){
            if(mp[i]==1){
                mp[i]=0;
                break;
            }
        }
        return i;
    }
    void addBack(int num) {
        if(mp[num]==0){
            mp[num]=1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */