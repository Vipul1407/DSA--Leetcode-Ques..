class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n= s.size();
        if(n<k)
        {
            return 0;
        }
        if(k<=1)
        {
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>vec(26,0);
            for(int j=i;j<n;j++)
            {
                vec[s[j]-'a']++;
                bool valid= true;
                for(int s:vec)
                {
                    if(s>0 && s<k)
                    {
                        valid= false;
                        break;
                    }
                }
                if(valid)
                {
                    ans= max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
