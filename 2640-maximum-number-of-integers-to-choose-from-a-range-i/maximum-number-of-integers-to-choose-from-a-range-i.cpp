class Solution {
public:
    int maxCount(vector<int>& banned, int n, int k) 
    {
        unordered_set<int>st(banned.begin(),banned.end());
        long sum=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(st.find(i)==st.end())
            {
                sum+=i;
                if(sum<=k)
                {
                    cnt++;
                }
                else
                {
                    return cnt;
                }
            }
        }
        return cnt;
    }
};