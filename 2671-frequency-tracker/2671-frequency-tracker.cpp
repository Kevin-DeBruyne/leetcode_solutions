class FrequencyTracker {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>mp2;
    FrequencyTracker() {
        mp.clear();
        mp2.clear();
    }
    void add(int n) {
        if(mp2.find(mp[n])!=mp2.end()){
            mp2[mp[n]]--;
            if(mp2[mp[n]]==0){
                mp2.erase(mp[n]);
            }
        }
        mp[n]++;
        mp2[mp[n]]++;
    }
    void deleteOne(int n) {
        if(mp.find(n)!=mp.end()){
            if(mp2.find(mp[n])!=mp2.end()){
                mp2[mp[n]]--;
                if(mp2[mp[n]]==0){
                    mp2.erase(mp[n]);
                }
            }
            mp[n]--;
            if(mp[n]==0){
                mp.erase(n);
            }
            else{
                mp2[mp[n]]++;
            }
        }
    }
    
    bool hasFrequency(int f) {
        if(mp2[f]>0){
            return 1;
        }
        return 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */