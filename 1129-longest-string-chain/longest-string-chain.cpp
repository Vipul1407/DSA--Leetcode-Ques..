class Solution {
public:
    static bool cmp(const string &a, const string &b)
    {
        return a.length()<b.length();//sort in increasing size..
    }
    bool issubseq(string &a, string &b)
    {
        if(b.size()-a.size()!=1)
        {
            return false;
        }
        int i=0,j=0;
        int change=0;
        while(i<a.size() || j<b.size())
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
                change++;
                if(change>1)
                {
                    return false;
                }
            }
        }
        return change==1;
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(begin(words),end(words),cmp);
        int n= words.size();
        vector<int>dp(n,1);//each alone is incresing subsequence..
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int previdx=0;previdx<i;previdx++)
            {
                if(issubseq(words[previdx],words[i]))
                {
                    dp[i]= max(dp[i],1+dp[previdx]);
                    ans= max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};