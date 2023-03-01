class Solution {
public:
    int minimumPartition(string s, int k) {
        long long num = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            num = num * 10 + s[i] - '0';
            if (num > k) {
                count++;
                num = s[i] - '0';
            }
            if (num > k)
                return -1;
        }
        return count + 1;
    }
};