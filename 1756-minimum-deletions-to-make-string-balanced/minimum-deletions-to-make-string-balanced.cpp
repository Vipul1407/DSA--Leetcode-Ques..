class Solution {
public:
    int minimumDeletions(string s) 
    {
        stack<char>st;
        int ans=0;
        int cb=0;
        for(auto i:s)
        {
            if(i=='b')
            {
                cb++;
            }
            else if(i=='a')
            {
                if(cb>0)
                {
                    ans++;
                    cb--;
                }
            }
        }
        return ans;
    }
};