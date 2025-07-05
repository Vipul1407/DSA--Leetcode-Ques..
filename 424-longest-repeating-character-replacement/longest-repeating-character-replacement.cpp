class Solution {
public:
    //METHOD-1
    //TC= O(2N)
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
};