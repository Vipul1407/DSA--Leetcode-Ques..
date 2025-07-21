class Solution {
public:
    string makeFancyString(string s) 
    {
        int n= s.size();
        string ans;
        ans+= s[0];
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i] && s[i+1]==s[i])
            {
                continue;
            }
            else
            {
                ans+= s[i];
            }
        }
        return ans;
    }
};