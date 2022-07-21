class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(iswalnum(s[i])){
                count++;
            }
        }
        if(count==0){
            return true;
        }
        while(left<right){
            if(!iswalnum(s[left])){
                while(!iswalnum(s[left])){
                    left++;
            }
            }
            if(!iswalnum(s[right])){
                while(!iswalnum(s[right])){
                    right--;
            }
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
        left++;
        right--;
        }
    return true;
    }
};