bool cmp(string& s1, string& s2){
    string t1=s1+s2;
    string t2=s2+s1;
    if(t1>t2){
        return true;
    }
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int cnt=0;
        for(auto x:nums){
            if(x==0){
                cnt++;
            }
        }
        if(cnt==nums.size()){
            return "0";
        }
        vector<string>sec;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            sec.push_back(s);
        }
        sort(sec.begin(), sec.end(),cmp);
        // reverse(sec.begin(), sec.end());
        for(auto x:sec){
            cout<<x<<" ";
        }
        string s="";
        for(auto x:sec){
            s+=x;
        }
        
        return s;
    }
};