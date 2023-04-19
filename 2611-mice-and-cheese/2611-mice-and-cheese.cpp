
#define PII pair<int, int>
    class Compare
    {
        public:
            bool operator()(PII a, PII b)
            {
                if (a.first-a.second>b.first-b.second)
                {
                    return false;
                }
                return true;
            }
    };
class Solution
{
    public:

        int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
        {
            int n = reward1.size();
            priority_queue<PII, vector < PII>, Compare> s;
            for (int i = 0; i < n; i++)
            {
                s.push({ reward1[i],
                    reward2[i] });
            }
            int cnt = 0;
            while (k > 0)
            {
                pair<int, int> x = s.top();
                cnt += x.first;
                s.pop();
                k--;
            }
            while (!s.empty())
            {
                pair<int, int> x = s.top();
                cnt += x.second;
                s.pop();
            }

            return cnt;
        }
};