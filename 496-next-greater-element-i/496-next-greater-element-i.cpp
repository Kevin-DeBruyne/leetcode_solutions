class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st;
        unordered_map <int,int> mp;
        vector<int>vec;
        int n=nums2.size();
        int i=0;
        while(i<n){
            if(st.empty()){
                st.push(nums2[i]);
                i++;
            }
            else if(nums2[i]>st.top()){
                while(!st.empty() && nums2[i]>st.top()){
                    mp[st.top()]=nums2[i];
                    st.pop();                        
                }
                st.push(nums2[i]);
                i++;
            }
            else{
                st.push(nums2[i]);
                i++;
            }
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<nums1.size();i++){
            vec.push_back(mp[nums1[i]]);
        }
        return vec;
    }
};