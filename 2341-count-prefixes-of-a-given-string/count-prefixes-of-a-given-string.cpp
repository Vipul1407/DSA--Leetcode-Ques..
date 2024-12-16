class Solution {
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        int cnt=0;
        for(auto i:words)
        {
            if(s.find(i)==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};