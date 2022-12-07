class Solution {
public:
    int count_one(int n) {
    int count=0;
        while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
    }
    vector<int> countBits(int n) {
        vector<int>vec;
        for(int i=0;i<=n;i++){
            vec.push_back(count_one(i));
        }    
        return vec;
    }
};