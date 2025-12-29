class Solution {
public:
    //METHOD-3
    //BUA APPROACH..
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            //1 day pass..
            int option1= costs[0]+ dp[i+1];

            //7 day pass..
            int idx= i;
            while(idx<n && days[idx]<days[i]+7)
            {
                idx++;
            }
            int option2= costs[1]+ dp[idx];

            //30 day pass..
            int newidx= i;
            while(newidx<n && days[newidx]<days[i]+30)
            {
                newidx++;
            }
            int option3= costs[2]+ dp[newidx];
            dp[i]= min(option1,min(option2,option3));
        }
        return dp[0];
    }
};
/*
    //METHOD-1
    //RECURSIVE APPROACH..
    int rec(int i,vector<int>& days, vector<int>& costs)
    {
        int n= days.size();
        if(i>=n)
        {
            return 0;
        }
        int option1= costs[0]+ rec(i+1,days,costs);

        int idx= i;
        while(idx<n && days[idx]<days[i]+7)
        {
            idx++;
        }
        int option2= costs[1]+ rec(idx,days,costs);

        int newidx= i;
        while(newidx<n && days[newidx]<days[i]+30)
        {
            newidx++;
        }
        int option3= costs[2]+ rec(newidx,days,costs);
        return min(option1,min(option2,option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        return rec(0,days,costs);
    }


    //METHOD-2
    //TDA APPROACH..
    int tda(int i,vector<int>& days, vector<int>& costs, vector<int>&dp)
    {
        int n= days.size();
        //base case..
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        //1 day pass..
        int option1= costs[0]+ tda(i+1,days,costs,dp);

        //7 day pass..
        int idx= i;
        while(idx<n && days[idx]<days[i]+7)
        {
            idx++;
        }
        int option2= costs[1]+ tda(idx,days,costs,dp);

        //30 day pass..
        int newidx= i;
        while(newidx<n && days[newidx]<days[i]+30)
        {
            newidx++;
        }
        int option3= costs[2]+ tda(newidx,days,costs,dp);
        return dp[i]= min(option1,min(option2,option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int>dp(days.size(),-1);
        return tda(0,days,costs,dp);
    }
*/