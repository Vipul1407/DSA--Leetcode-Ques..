class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& ori, vector<char>& chan, vector<int>& cost) 
    {
        int n= s.size();
        vector<vector<int>>dis(26,vector<int>(26,INT_MAX));
        for(int i=0;i<ori.size();i++)
        {
            dis[ori[i]-'a'][chan[i]-'a']= min(cost[i],dis[ori[i]-'a'][chan[i]-'a']);
        }
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                    {
                        dis[i][j]= min(dis[i][j], dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                int d= dis[s[i]-'a'][t[i]-'a'];
                if(d!=INT_MAX)
                {
                    ans+=d;
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};