class Solution {
public:
    //Space Optimized...
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n= days.size();
        //queue storing {curr day, cost}....
        queue<pair<int,int>>month;
        queue<pair<int,int>>week;
        int ans=0;
        for(auto currday:days)
        {
            //poping previous than 30days..
            while(month.size() && month.front().first+30<=currday)
            {
                month.pop();
            }
            //poping previous than 7days..
            while(week.size() && week.front().first+7<=currday)
            {
                week.pop();
            }
            month.push({currday,costs[2]+ans});
            week.push({currday,costs[1]+ans});
            ans= min(ans+costs[0],min(month.front().second,week.front().second));
        }
        return ans;
    }
};
/*
// USING FOR LOOP----------------------------------------->
//  recursive
//  TC=O(expon)
int rec(vector<int> &days, vector<int> &cost, int index)
{
    int n = days.size();
    if (index >= n)
    {
        return 0;
    }
    // 1day pass
    int op1 = cost[0] + rec(days, cost, index + 1);

    // 7day pass
    // for loop checking the conditions that our index should not cross the size of no. of days(i<n)
    // and day no. is less then the max day limit of the 7day pass(days[i]<days[index])
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
    {
        // for loop only to update i value upto next7days after with above conditions and pass i not index in rec
    }
    // not do index+1 in rec as it is already done by for loop above
    int op2 = cost[1] + rec(days, cost, i);

    // 30day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
    {
        // only to update i value upto next 30days and make sure we pass i not index in rec fun
    }
    int op3 = cost[2] + rec(days, cost, i);

    // return min value from all 3
    return min(op1, min(op2, op3));
}

// tda
// TC= O(1) dp array size is upto 366 max (fixed)
int tda(vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    int n = days.size();
    if (index >= n)
    {
        return 0;
    }
    // dp->ka size n+1 h
    // lekin only index is changing so dp[index] me store krenge
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int op1 = cost[0] + tda(days, cost, index + 1, dp);
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int op2 = cost[1] + tda(days, cost, i, dp);
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int op3 = cost[2] + tda(days, cost, i, dp);
    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

// bua
// O(N) both TC,SC
int bua(vector<int> &days, vector<int> &cost)
{
    int n = days.size();
    // we need to find min, hence initialized by max
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0; // here dp[n] given
    // so we make loop from n-1 to 0
    // and infinal we return dp[0]
    // reverse from previous ques.in which loop 1->n and return dp[n]
    for (int k = n - 1; k >= 0; k--)
    {
        // 1day
        int op1 = cost[0] + dp[k + 1];
        // 7day
        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int op2 = cost[1] + dp[i];
        // 30day
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int op3 = cost[2] + dp[i];
        dp[k] = min(op1, min(op2, op3));
    }
    return dp[0];
}

// space optimization
// O(1)->here we use 2 queues month,week why O(1) then?
// becoz month queue has max 30 elements and week has max 7 elements
// TC=O(N)
// SC=O(1)
int space(vector<int> &days, vector<int> &cost)
{
    int ans = 0;
    //<int,int> means <day,cost>
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;
    for (int day : days)
    {
        // day is indicating the current day
        //  step1:remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }
        while (!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }
        // step2:add cost for curr day
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));
        // step3:update ans
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}

// USING WHILE LOOP--------------------------------------------------->

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

// METHOD-3
// BUA
// BEATS 100%
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int day1 = costs[0] + dp[i + 1];
        int k = i;
        while (k < n && days[k] < days[i] + 7)
        {
            k++;
        }
        int day7 = costs[1] + dp[k];
        while (k < n && days[k] < days[i] + 30)
        {
            k++;
        }
        int day30 = costs[2] + dp[k];
        dp[i] = min(day1, min(day7, day30));
    }
    return dp[0];
}
*/