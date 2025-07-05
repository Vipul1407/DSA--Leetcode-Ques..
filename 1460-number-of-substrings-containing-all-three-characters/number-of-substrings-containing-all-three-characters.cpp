class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n= s.size();
        vector<int>mp(3,0);
        int l=0,r=0,ans=0;
        while(r<n)
        {
            mp[s[r]-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0)
            {
                ans+= n-r;
                mp[s[l]-'a']--;
                l++;
            }
            r++;
        }   
        return ans;
    }
};