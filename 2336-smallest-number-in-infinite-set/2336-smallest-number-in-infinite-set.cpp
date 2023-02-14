class SmallestInfiniteSet {
public:
    map<int,bool>mp;
    SmallestInfiniteSet() {

    }
    int popSmallest() {
        int i=1;
        while(true){
            if(mp[i]==false){
                break;
            }
            i++;
        }
        mp[i]=true;
        return i;
    }
    void addBack(int num) {
        if(mp[num]==true){
            mp[num]=false;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */