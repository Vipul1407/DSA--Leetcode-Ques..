class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string ans="";
        for(auto i:words)
        {
            ans+=i;
            if(ans==s)
            {
                return true;
            }
            // if(ans.length()>s.length())
            // {
            //     return false;
            // }
        }
        return false;
    }
};