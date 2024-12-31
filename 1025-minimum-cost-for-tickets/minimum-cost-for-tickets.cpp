class Solution {
public:
    int rec(int i,vector<int>& days, vector<int>& costs, vector<int>&dp)
    {
        if(i>=days.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        //pass-1day
        int day1= costs[0]+ rec(i+1,days,costs,dp);
        //pass-7day
        int k=i;
        while(k<days.size() && days[k]<days[i]+7)
        {
            k++;
        }
        int day7= costs[1]+ rec(k,days,costs,dp);
        //pass-30day
        while(k<days.size() && days[k]<days[i]+30)
        {
            k++;
        }
        int day30= costs[2]+ rec(k,days,costs,dp);
        return dp[i]= min(day1,min(day7,day30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int>dp(days.size(),-1);
        return rec(0,days,costs,dp);
    }
};