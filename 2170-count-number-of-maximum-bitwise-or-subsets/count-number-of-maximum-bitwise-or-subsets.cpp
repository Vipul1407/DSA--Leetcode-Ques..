class Solution {
public:
    int solve(int i,vector<int>& nums,int temp, int &maxor, vector<vector<int>>&dp)
    {
        if(i==nums.size())
        {
            if(temp==maxor)
            {
                return 1;
            }
            else return 0;
        }
        if(dp[i][temp]!=-1)
        {
            return dp[i][temp];
        }
        int take= solve(i+1,nums,temp|nums[i],maxor,dp);
        int notake= solve(i+1,nums,temp,maxor,dp);
        return dp[i][temp]= take+notake;
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n= nums.size();
        int cnt=0;
        int maxor= 0;
        for(auto i:nums)
        {
            maxor|=i;
        }
        int temp=0;
        vector<vector<int>>dp(n+1,vector<int>(maxor+1,-1));
        return solve(0,nums,temp,maxor,dp);    
    }
};