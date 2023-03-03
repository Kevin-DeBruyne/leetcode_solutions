class Solution
{
    public:
        bool isItPossible(string word1, string word2)
        {
            unordered_map<char, int> mp1;
            unordered_map<char, int> mp2;
            for (auto x: word1)
            {
                mp1[x]++;
            }
            for (auto x: word2)
            {
                mp2[x]++;
            }
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                unordered_map<char, int> t1;
                unordered_map<char, int> t2;
                t1=mp1;
                t2=mp2;
                    if (t1[char(i + 97)] && t2[char(j + 97)])
                    {
                        t1[char(i + 97)]--;
                        if(t1[char(i+97)]==0){
                            t1.erase(char(i+97));
                        }
                        t1[char(j + 97)]++;
                        t2[char(i + 97)]++;
                        t2[char(j + 97)]--;
                        if(t2[char(j+97)]==0){
                            t2.erase(char(j+97));
                        }
                        if (t1.size() == t2.size())
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
};