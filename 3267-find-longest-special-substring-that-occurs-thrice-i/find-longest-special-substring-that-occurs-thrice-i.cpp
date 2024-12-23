class Solution {
public:
    int maximumLength(string s) 
    {
        int n= s.length();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string str;
            for(int j=i;j<n;j++)
            {
                if(str=="" || s[j]==s[i])
                {
                    str+= s[j];     
                }
                else
                {
                    break;
                }
                mp[str]++;
            }
        }
        int maxcnt=-1;
        for(auto i:mp)
        {
            int len= i.first.size();
            if(i.second>=3 && len>maxcnt)
            {
                maxcnt= len;
            }
        }
        return maxcnt;
    }
};