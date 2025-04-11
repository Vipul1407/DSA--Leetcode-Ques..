class Solution {
public:
    //METHOD-2
    //TDA APPROACH...
    long long tda(int i,vector<vector<int>>& ques, vector<long>&dp)
    {
        if(i>=ques.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        long long take= ques[i][0]+ tda(i+ques[i][1]+1,ques,dp);
        long long notake= tda(i+1,ques,dp);
        return dp[i]= max(take,notake);
    }
    long long mostPoints(vector<vector<int>>& ques) 
    {
        int n=ques.size();
        vector<long>dp(n,-1);
        return tda(0,ques,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE APPROACH...
    long long rec(int i,vector<vector<int>>& ques)
    {
        if(i>=ques.size())
        {
            return 0;
        }
        long long take= ques[i][0]+ rec(i+ques[i][1]+1,ques);
        long long notake= rec(i+1,ques);
        return max(take,notake);
    }
    long long mostPoints(vector<vector<int>>& ques) 
    {
        int n=ques.size();
        return rec(0,ques);
    }
*/