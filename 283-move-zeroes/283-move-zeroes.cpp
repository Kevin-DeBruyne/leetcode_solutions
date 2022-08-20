class Solution {
public:
    void moveZeroes(vector<int>& nums) {
	    int count=0;
        int n=nums.size();
	    for(int i=0;i<n;i++){
	        if(nums[i]){
	            swap(nums[i], nums[count]);
	            count++;
	        }
	    }
	
    }
};