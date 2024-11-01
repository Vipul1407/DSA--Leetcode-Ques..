class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans="";
        int n=s.size();
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
               cnt++;
            }
            else
            {
                cnt=1;
            }
            if(cnt<=2)
            {
                ans+=s[i-1];
            }
        }
        ans+=s.back();
        return ans;
    }
};