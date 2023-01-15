class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int add=0;
        int add2=0;
        for(auto x:nums){
            add+=x;
            string temp=to_string(x);
            for(int i=0;i<temp.size();i++){
                add2+=int(temp[i])-48;
            }
            // int i=10;
            // while(x>0){
            //     add2+=x%10;
            //     x=x/10;
            // }
        }
        cout<<add<<" "<<add2<<endl;
        return abs(add-add2);
    }
};