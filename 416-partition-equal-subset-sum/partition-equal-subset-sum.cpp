class Solution {
public:
    //METHOD-3
    //BUA..
    bool canPartition(vector<int>& nums) 
    {
        int s= accumulate(begin(nums),end(nums),0);
        int n= nums.size();
        int tar= s/2;
        if(s%2!=0)
        {
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(tar+1,0));
        //base case..
        //if(tar==0) return 1
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=tar;j++)
            {
                //cannot take duplicates==> i+1
                bool take= (j-nums[i]>=0) ? dp[i+1][j-nums[i]]:0;
                bool notake=dp[i+1][j];
                dp[i][j]= take || notake;
            }
        }
        return dp[0][tar];
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    bool rec(int i,vector<int>& nums,int tar)
    {
        if(tar==0)
        {
           return true; 
        }
        if(i>=nums.size() || tar<0)
        {
            return false;
        }
        //cannot take duplicates==> i+1
        bool take= rec(i+1,nums,tar-nums[i]);
        bool notake= rec(i+1,nums,tar);
        return take || notake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int s= accumulate(begin(nums),end(nums),0);
        if(s%2!=0)
        {
            return false;
        }
        return rec(0,nums,s/2);
    }

    //METHOD-1
    //TDA..
    bool tda(int i,vector<int>& nums,int tar,vector<vector<int>>&dp)
    {
        if(tar==0)
        {
           return true; 
        }
        if(i>=nums.size() || tar<0)
        {
            return false;
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        //cannot take duplicates==> i+1
        bool take= tda(i+1,nums,tar-nums[i],dp);
        bool notake= tda(i+1,nums,tar,dp);
        return dp[i][tar]= take || notake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int s= accumulate(begin(nums),end(nums),0);
        if(s%2!=0)
        {
            return false;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(s/2+1,-1));
        return tda(0,nums,s/2,dp);
    }
*/