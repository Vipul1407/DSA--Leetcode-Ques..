class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n= s.size();
        int l=0,r=0,ans=0;
        unordered_map<int,int>mp;
        while(r<n)
        {
            mp[s[r]]++;
            while(l<r && mp[s[r]]>1)
            {
                mp[s[l]]--;
                l++;
            }
            ans= max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};