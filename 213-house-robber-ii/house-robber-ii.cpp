class Solution {
public:
    //METHOD-2
    //TDA
    int tda(int i,vector<int>& nums, vector<int>&dp)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int take= nums[i]+tda(i+2,nums,dp);
        int notake= tda(i+1,nums,dp);
        return dp[i]= max(take,notake);
    }
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        vector<int>a1(begin(nums)+1,end(nums));
        vector<int>a2(begin(nums),end(nums)-1);
        return max(tda(0,a1,dp1),tda(0,a2,dp2));
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,vector<int>& nums)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        int take= nums[i]+rec(i+2,nums);
        int notake= rec(i+1,nums);
        return max(take,notake);
    }
    int rob(vector<int>& nums) 
    {
        vector<int>a1(begin(nums)+1,end(nums));
        vector<int>a2(begin(nums),end(nums)-1);
        return max(rec(0,a1),rec(0,a2));
    }
*/