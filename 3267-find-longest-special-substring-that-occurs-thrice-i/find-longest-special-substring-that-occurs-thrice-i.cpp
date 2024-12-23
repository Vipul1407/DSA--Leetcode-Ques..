class Solution {
public:
    int maximumLength(string s) 
    {
        int n= s.length();
        map<pair<char,int>,int>mp;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            int cnt=0;
            for(int j=i;j<n;j++)
            {
               if(s[j]==ch) 
               {
                    cnt++;
               }
               else
               {
                    break;
               }
               mp[{ch,cnt}]++;
            }
        }
        int maxlen= -1;
        for(auto i:mp)
        {
            if(i.second>=3)
            {
                maxlen= max(maxlen,i.first.second);
            }
        }
        return maxlen;
    }
};
/*
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
*/