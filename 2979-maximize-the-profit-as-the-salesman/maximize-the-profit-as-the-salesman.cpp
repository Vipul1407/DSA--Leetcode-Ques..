class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) 
    {
        unordered_map<int,vector<int>>mp;
        vector<int>dp(n,0);
        for(int i=0;i<offers.size();i++)
        {
            mp[offers[i][1]].push_back(i);
        }
        int best=0;

        for(int i=0;i<n;i++)
        {
            for(auto j:mp[i])
            {
                int conflict= offers[j][0]-1;
                int amount= offers[j][2];
                if(conflict>=0)
                {
                    amount+= dp[conflict];
                }
                best= max(best,amount);
                dp[i]= max(dp[i],best);
            }
            dp[i]= best;
        }
        return best;
    }
};
//map= [1,0,1,1,0]
// dp= [0,0,0,0,0]
// best=0
// lastconflict=-1
//