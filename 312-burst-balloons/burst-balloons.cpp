class Solution {
public:
    //METHOD-2
    //TDA..
    int tda(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans= INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int cost= nums[i-1]*nums[k]*nums[j+1] + tda(i,k-1,nums,dp) + tda(k+1,j,nums,dp);
            ans= max(ans,cost);
        }   
        return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) 
    {
        int n= nums.size();
        nums.insert(begin(nums),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return tda(1,n,nums,dp);
    }
};
/*
    //METHOD-1
    //RECUSIVE..
    int rec(int i,int j,vector<int>&nums)
    {
        if(i>j)
        {
            return 0;
        }
        int ans= INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int cost= nums[i-1]*nums[k]*nums[j+1] + rec(i,k-1,nums) + rec(k+1,j,nums);
            ans= max(ans,cost);
        }   
        return ans;
    }
    int maxCoins(vector<int>& nums) 
    {
        int n= nums.size();
        nums.insert(begin(nums),1);
        nums.push_back(1);
        return rec(1,n,nums);
    }
*/