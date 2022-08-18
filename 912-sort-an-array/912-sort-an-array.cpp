class Solution {
public:
    static bool comp(int a, int b){
        if(a<b){
            return true;
        }
        return false;
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};