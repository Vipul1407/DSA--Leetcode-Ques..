class Solution {
public:
    //curr-->to store how many 'A' in our formed number..
    //clip-->to track how many 'A' is copied in our cipboard..
    int rec(int n, int curr, int clip, vector<vector<int>>&dp)
    {
        if(curr==n)
        {
            return 0;
        }
        if(curr>n)
        {
            return 1e9;
        }
        if(dp[curr][clip]!=-1)
        {
            return dp[curr][clip];
        }
        //2 operations-:

        //either copy all + paste -->2steps
        //curr will get twice, clip will be our curr
        int copypaste= 2+ rec(n,curr*2,curr,dp);

        //either paste -->1step
        //curr will add up by curr, clip will remain same 
        int paste= 1+ rec(n,curr+clip,clip,dp);

        return dp[curr][clip]= min(copypaste, paste);
        
    }
    int minSteps(int n) 
    {
        //becoz we have already have 1 'A' in clipboard..
        if(n==1)
        {
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //add 1 in final ans as copy is req. as initially only 'A' in clipboard 
        //so we need to copy it to clipboard that takes 1 operation..
        return 1+rec(n,1,1,dp);
    }
};