class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans="";
        int n=s.size();
        int cnt=0;
        for(auto c:s)
        {
            if(ans=="" || ans.back()==c)
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            if(cnt<=2)
            {
                ans+=c;
            }
        }
        return ans;
    }
};