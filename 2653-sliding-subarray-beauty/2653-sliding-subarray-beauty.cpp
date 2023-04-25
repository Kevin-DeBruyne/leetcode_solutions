class Solution
{
    public:
        int getMin(multiset<int> &st, int &x)
        {
            if (st.size() < x)
            {
                return 0;
            }
            return *next(st.begin(), x - 1);
        }
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        multiset<int> st;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            if(nums[i]<0){
                st.insert(nums[i]);
            }
        }
        int i = 0;
        int j = k;
        int n = nums.size();
        res.push_back(getMin(st, x));
        while (j < n)
        {
            int it = nums[i];
            if(it<0){
                st.erase(st.find(it));
            }
            if (nums[j] < 0)
            {
                st.insert(nums[j]);
            }
            i++;
            j++;
            res.push_back(getMin(st, x));
        }
        return res;
    }
};