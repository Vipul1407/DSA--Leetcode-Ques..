class Solution {
public:
    //METHOD-5
    //BINARY SEARCH..
    //TC= O(NLOGN)
    //Only length is preserved not the actual sequence..
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
           if(nums[i]>ans.back())
           {
                ans.push_back(nums[i]);
           }
           else
           {
                //lower bound nikal nums[i] ka ans vector me..
                int just_greater_index= lower_bound(begin(ans),end(ans),nums[i])- begin(ans);
                ans[just_greater_index]= nums[i];
           }
        }
        //only length is corect but the order is wrong...
        return ans.size();
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i, int previdx, vector<int>& nums)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        int take=0;
        if(previdx==-1 || nums[previdx]<nums[i])
        {
            take= 1+rec(i+1,i,nums);
        }
        int notake= rec(i+1,previdx,nums);
        return max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        return rec(0,-1,nums);
    }

    //METHOD-2
    //TDA..
    int rec(int i, int previdx, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        if(dp[i][previdx+1]!=-1)
        {
            return dp[i][previdx+1];
        }
        int take=0;
        if(previdx==-1 || nums[previdx]<nums[i])
        {
            take= 1+rec(i+1,i,nums,dp);
        }
        int notake= rec(i+1,previdx,nums,dp);
        return dp[i][previdx+1]= max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
    }

    //METHOD-3
    //BUA..
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int previdx=n-1;previdx>=-1;previdx--)
            {
                int take=0;
                if(previdx==-1 || nums[previdx]<nums[i])
                {
                    take= 1+dp[i+1][i+1];//making it y= i+1 
                }
                int notake= dp[i+1][previdx+1];
                dp[i][previdx+1]= max(take,notake);
            }
        }
        return dp[0][0];
    }

    //METHOD-4
    //SPACE OPTIMIZATION..
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int previdx=n-1;previdx>=-1;previdx--)
            {
                int take=0;
                if(previdx==-1 || nums[previdx]<nums[i])
                {
                    take= 1+next[i+1];//making it y= i+1 
                }
                int notake= next[previdx+1];
                curr[previdx+1]= max(take,notake);
            }
            next= curr;
        }
        return next[0];
    }

    //METHOD-4
    //MORE SPACE OPTIMIZATION..
    //1D dp array only, this way also used for printing also..
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        //initalizing with 1 since each element can be part of subsequence alone..
        vector<int>dp(n+1,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int previdx=0;previdx<=i-1;previdx++)
            {
                if(nums[previdx]<nums[i])
                {
                    dp[i]= max(dp[i],dp[previdx]+1);
                    maxi= max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
*/