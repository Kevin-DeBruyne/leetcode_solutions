class Solution {
public:
    vector<vector<int>>solve(vector<int>& nums){
        if(nums.size()==0){
            return {{}};
        }
        vector<int>temp;
        for(int i=1;i<nums.size();i++){
            temp.push_back(nums[i]);
        }        
        vector<vector<int>>pushing;
        vector<vector<int>>vec_t=subsets(temp);
        for(auto x:vec_t){
            pushing.push_back(x);
        }
        for(auto x:vec_t){
            vector<int>hello=x;
            hello.push_back(nums[0]);
            pushing.push_back(hello);
        }
        return pushing;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums);
    }
	// vector<string>solve(string s){
	//     if(s.length()==0){
	// 	        return {""};
	// 	    }
	// 	    char c=s[0];
	// 	    string temp=s.substr(1);
	// 	    vector<string>a=solve(temp);
	// 	    vector<string>ans;
	// 	    for(int i=0;i<a.size();i++){
	// 	        ans.push_back(a[i]);
	// 	        ans.push_back(c+a[i]);
	// 	    }
	// 	    return ans;
	// }
	// 	vector<string> AllPossibleStrings(string s){
	// 	    vector<string>x=solve(s);
	// 	    sort(x.begin(),x.end());
	// 	    x.erase(x.begin());
	// 	    return x;
	// 	}
};