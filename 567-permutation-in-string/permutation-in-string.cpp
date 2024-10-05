class Solution {
public:
    bool match(vector<int>&a, vector<int>&b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        int n=s1.size();
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(auto i:s1)
        {
            a[i-'a']++;
        }
        int window= n-1;
        for(int i=0;i<s2.size();i++)
        {
            b[s2[i]-'a']++;
            if(i>=window)
            {
                if(match(a,b))
                {
                    return true;
                }
                else
                {
                    b[s2[i-window]-'a']--;
                }
            }
        }
        return false;
    }
};