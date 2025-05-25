class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string,int>mp;
        for(auto i:words)
        {
            mp[i]++;
        }
        int flag=1;
        int ans=0;
        for(auto it:mp)
        {
            auto s=it.first;
            if(s[0]==s[1])
            {
                if(it.second%2==0)
                {
                    ans+=it.second*2;
                }
                else
                {
                    ans+=(it.second-1)*2;
                    if(flag==1)
                    {
                        ans+=2;
                        flag++;
                    }
                }
            }

            else
            {
                string r=s;
                reverse(r.begin(),r.end());
                if(mp.find(r)!=mp.end())
                {
                    ans+=min(mp[s],mp[r])*2;
                }
            }
        }
        return ans;
    }
};
