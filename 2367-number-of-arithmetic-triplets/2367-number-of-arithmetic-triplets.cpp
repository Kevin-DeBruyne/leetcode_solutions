class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
int count=0;
int n= nums.size();
unordered_set<int> s;

    for(int i=0;i<n;i++)
    {
        s.insert(nums[i]);
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]-nums[i]==diff && s.find(nums[i]-diff)!=s.end())
                count++;
        }
    }
    return count;
	}
};