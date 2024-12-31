class Solution {
public:
    // USING WHILE LOOP--------------------------------------------------->
    //METHOD-3
    //BUA
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n= days.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int day1= costs[0]+ dp[i+1];
            int k=i;
            while(k<n && days[k]<days[i]+7)
            {
                k++;
            }
            int day7= costs[1]+ dp[k];
            while(k<n && days[k]<days[i]+30)
            {
                k++;
            }
            int day30= costs[2]+ dp[k];
            dp[i]= min(day1,min(day7,day30));
        }
        return dp[0];
    }
};
/*
// METHOD-1
// RECURSIVE
int rec(int i, vector<int> &days, vector<int> &costs)
{
    if (i >= days.size())
    {
        return 0;
    }
    // pass-1day
    int day1 = costs[0] + rec(i + 1, days, costs);
    // pass-7day
    int k = i;
    while (k < days.size() && days[k] < days[i] + 7)
    {
        k++;
    }
    int day7 = costs[1] + rec(k, days, costs);
    // pass-30day
    while (k < days.size() && days[k] < days[i] + 30)
    {
        k++;
    }
    int day30 = costs[2] + rec(k, days, costs);
    return min(day1, min(day7, day30));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return rec(0, days, costs);
}

// METHOD-2
// TDA
// BEATS 100%
int tda(int i, vector<int> &days, vector<int> &costs, vector<int> &dp)
{
    if (i >= days.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    // pass-1day
    int day1 = costs[0] + tda(i + 1, days, costs, dp);
    // pass-7day
    int k = i;
    while (k < days.size() && days[k] < days[i] + 7)
    {
        k++;
    }
    int day7 = costs[1] + tda(k, days, costs, dp);
    // pass-30day
    while (k < days.size() && days[k] < days[i] + 30)
    {
        k++;
    }
    int day30 = costs[2] + tda(k, days, costs, dp);
    return dp[i] = min(day1, min(day7, day30));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    vector<int> dp(days.size(), -1);
    return tda(0, days, costs, dp);
}
*/