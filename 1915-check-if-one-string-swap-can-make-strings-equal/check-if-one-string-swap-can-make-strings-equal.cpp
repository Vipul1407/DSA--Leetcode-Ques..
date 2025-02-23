class Solution {
public:
    
    // METHOD-2
    // OPTIMIZED APPROACH..
    bool areAlmostEqual(string s1, string s2) 
    {
        if(s1==s2)
        {
            return true;
        }
        int swapreq=0;
        int first=0;
        int second=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                swapreq++;
                if(swapreq>2)
                {
                    return false;
                }
                else if(swapreq==1)
                {
                    first=i;
                }
                else
                {
                    second=i;
                }
            }
        }
        return s1[first]==s2[second] && s1[second]==s2[first];
    }
};
/*
// METHOD-1
// BRUTE FORCE
bool areAlmostEqual(string s1, string s2)
{
    if (s1 == s2)
    {
        return true;
    }
    vector<int> v1(26, 0);
    vector<int> v2(26, 0);

    int swapreq = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            swapreq++;
        }
        if (swapreq > 2)
        {
            return false;
        }
        v1[s1[i] - 'a']++;
        v2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}
*/