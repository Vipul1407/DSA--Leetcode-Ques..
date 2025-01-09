class Solution {
public:
    // METHOD-2
    // USING FIND
    int prefixCount(vector<string>& words, string pref) 
    {
        int n= words.size();
        int cnt=0;
        int m= pref.size();
        for(int i=0;i<n;i++)
        {
            if(words[i].find(pref)==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
/*
// METHOD-1
// USING SUBSTRING
int prefixCount(vector<string> &words, string pref)
{
    int cnt = 0;
    int n = words.size();
    int m = pref.size();
    for (int i = 0; i < n; i++)
    {
        string str = words[i].substr(0, m);
        if (str == pref)
        {
            cnt++;
        }
    }
    return cnt;
}
*/