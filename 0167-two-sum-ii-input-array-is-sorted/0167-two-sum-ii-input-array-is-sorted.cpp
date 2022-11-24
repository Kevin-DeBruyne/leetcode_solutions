class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0;
        vector<int>vec;
        int r=n-1;
        while(l<=r){
            if(numbers[l]+numbers[r]>target){
                r--;
            }
            else if(numbers[l]+numbers[r]<target){
                l++;
            }
            else{
                vec.push_back(l+1);
                vec.push_back(r+1);
                break;
                
            }
        }
        return vec;
    }
};