class Solution {
public:
    //TC= O(N)------------------>
    int maximumLength(string s) 
    {
        int n= s.size();
        vector<vector<int>>vec(26,vector<int>(n+1,0));
        char ch= s[0];
        int cnt=0;
        for(auto i:s)
        {
            if(i==ch)
            {
                cnt++;
            }
            else
            {
                ch=i;
                cnt=1;
            }
            vec[i-'a'][cnt]++;
        }
        int maxlen=-1;
        for(int row= 0;row<26;row++)
        {
            int sum=0;
            //becoz we need maxlen so will traverse from right..
            for(int col=n;col>=1;col--)
            {
                sum+= vec[row][col];
                if(sum>=3)
                {
                    maxlen= max(maxlen,col);
                    break;//once found it will be the max so we can break easily
                }
            }
        }
        return maxlen;
    }
};

//TC= O(N^2)---------------------->
/*
// METHOD-1
// using unordered map...
//TC= O(N^2)
int maximumLength(string s)
{
    int n = s.length();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string str;
        for (int j = i; j < n; j++)
        {
            if (str == "" || s[j] == s[i])
            {
                str += s[j];
            }
            else
            {
                break;
            }
            mp[str]++;
        }
    }
    int maxcnt = -1;
    for (auto i : mp)
    {
        int len = i.first.size();
        if (i.second >= 3 && len > maxcnt)
        {
            maxcnt = len;
        }
    }
    return maxcnt;
}

// METHOD-2
// using map of pair<int,int>,int
//TC= O(N^2)
int maximumLength(string s)
{
    int n = s.length();
    map<pair<char, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (s[j] == ch)
            {
                cnt++;
            }
            else
            {
                break;
            }
            mp[{ch, cnt}]++;
        }
    }
    int maxlen = -1;
    for (auto i : mp)
    {
        if (i.second >= 3)
        {
            maxlen = max(maxlen, i.first.second);
        }
    }
    return maxlen;
}
*/