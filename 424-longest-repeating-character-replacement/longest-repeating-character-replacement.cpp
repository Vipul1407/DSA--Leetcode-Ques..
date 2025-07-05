class Solution {
public:
    //METHOD-2
    //TC= O(N) USING IF
    int characterReplacement(string s, int k) 
    {
        int n= s.size();
        int l=0,r=0,ans=0,maxfreq=0;
        vector<int>mp(26,0);
        while(r<n)
        {
            mp[s[r]-'A']++;
            maxfreq= max(maxfreq,mp[s[r]-'A']);

            if((r-l+1)-maxfreq>k)
            {
                mp[s[l]-'A']--;
                for(auto i:mp)
                {
                    maxfreq= max(maxfreq,i);
                }
                l++;
            }
            if((r-l+1)-maxfreq<=k)
            {
                ans= max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //TC= O(2N)  USING WHILE
    int characterReplacement(string s, int k) 
    {
        int n= s.size();
        int l=0,r=0,ans=0,maxfreq=0;
        vector<int>mp(26,0);
        while(r<n)
        {
            mp[s[r]-'A']++;
            maxfreq= max(maxfreq,mp[s[r]-'A']);

            while((r-l+1)-maxfreq>k)
            {
                mp[s[l]-'A']--;
                for(auto i:mp)
                {
                    maxfreq= max(maxfreq,i);
                }
                l++;
            }
            ans= max(ans,r-l+1);
            r++;
        }
        return ans;
    }
*/