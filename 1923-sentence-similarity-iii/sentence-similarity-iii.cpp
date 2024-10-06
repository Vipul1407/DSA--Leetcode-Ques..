class Solution
{
    public:
        bool areSentencesSimilar(string s1, string s2)
        {
           	//to ensure that s1 is bigger
            if (s1.size() < s2.size())
            {
                swap(s1, s2);
            }
            deque<string> d1;
            deque<string> d2;
            string token;
            stringstream ss1(s1);
            stringstream ss2(s2);
            while (ss1 >> token)
            {
                d1.push_back(token);
            }
            while (ss2 >> token)
            {
                d2.push_back(token);
            }
            while (d1.size() && d2.size() && d1.front() == d2.front())
            {
                d1.pop_front();
                d2.pop_front();
            }
            while (d2.size() && d1.back() == d2.back())
            {
                d1.pop_back();
                d2.pop_back();
            }
            return d2.empty();
        }
};