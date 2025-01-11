class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        int n= s.length();
        if(n==k)
        {
            return true;
        }
        if(n<k)
        {
            return false;
        }
        vector<int>freq(26,0);
        int odd=0;
        for(auto i:s)
        {
            freq[i-'a']++;
        }
        for(auto i:freq)
        {
            if(i%2==1)
            {
                odd++;
            }
        }
        return odd<=k;
    }
};