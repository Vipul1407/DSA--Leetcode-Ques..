class Solution {
public:
    //METHOD-2
    //TDA..
    int solve(int i,vector<int>& nums,int cnt,vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            if(cnt%3==0)
            {
                return cnt;
            }
            return 0;
        }
        int rem= cnt%3;
        //if we already have a larger ans stored in dp then return 0 directly..
        if(dp[i][rem]>= cnt)
        {
            return 0;
        }
        //stored cnt in dp earlier..
        dp[i][rem]= cnt;
        int take= solve(i+1,nums,cnt+nums[i],dp);
        int notake= solve(i+1,nums,cnt,dp);
        return max(take,notake);
    }
    int maxSumDivThree(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return solve(0,nums,0,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,vector<int>& nums,int cnt)
    {
        if(i>=nums.size())
        {
            if(cnt%3==0)
            {
                return cnt;
            }
            return 0;
        }
        int rem= cnt%3;
        
        int take= rec(i+1,nums,cnt+nums[i]);
        int notake= rec(i+1,nums,cnt);
        return dp[i][rem]= max(take,notake);
    }
    int maxSumDivThree(vector<int>& nums) 
    {
        int n= nums.size();
        return rec(0,nums,0);
    }
*/