class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int ans=0;
        int n= s.size();
        vector<int>freq(26,0);
        for(auto i:s)
        {
            freq[i-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            if(freq[s[i]-'a']<k)
            {
                int left= longestSubstring(s.substr(0,i),k);
                int right= longestSubstring(s.substr(i+1),k);
                return max(left,right);
            }
        }
        return n; 
    }
};