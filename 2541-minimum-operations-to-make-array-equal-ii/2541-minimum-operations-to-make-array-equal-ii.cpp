class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum=0;
        long long t;
        if(nums1!=nums2 && k==0){
            return -1;
        }
        else if(nums1==nums2){
            return 0;
        }
        for(int i=0;i<nums1.size();i++){
            sum+=nums1[i]-nums2[i];
            t=nums1[i]-nums2[i];
            if(t%k!=0){
                return -1;
            }
        }
        if(sum){
            return -1;
        }
        else{
        long long temp=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]-nums2[i]>0){
                temp+=nums1[i]-nums2[i];
            }
        }
        return temp/k;
        }
    }
};