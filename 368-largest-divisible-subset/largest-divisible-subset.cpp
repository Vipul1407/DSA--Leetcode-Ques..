class Solution {
public:
    //METHOD-3
    //BOTTOM UP
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>previdx(n,-1);
        int idx=0;
        int maxlen=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]= dp[j]+1;
                        previdx[i]=j;
                    }
                    if(dp[i]>maxlen)
                    {
                        maxlen= dp[i];
                        idx=i;
                    }
                }
            }
        }
        vector<int>res;
        while(idx!=-1)
        {
            res.push_back(nums[idx]);
            idx= previdx[idx];
        }
        return res;
    }
};

/*
    //METHOD-1
    //RECURSIVE...
    //TLE...
    void solve(int i,int prev,vector<int>& nums,vector<int>& temp,vector<int>& ans)
    {
        if(i>=nums.size())
        {
            if(temp.size()>ans.size())
            {
                ans= temp;
            }
            return;
        }
        if(prev==-1 || nums[i]%prev==0)
        {
            temp.push_back(nums[i]);
            solve(i+1,nums[i],nums,temp,ans);
            temp.pop_back();
        }
        solve(i+1,prev,nums,temp,ans);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<int>ans;
        solve(0,-1,nums,temp,ans);
        return ans;
    }

    //METHOD-2
    //TDA...
    //WRONG ANS...
    void solve(int i,int previdx,vector<int>& nums,vector<int>& temp,vector<int>& ans, vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            if(temp.size()>ans.size())
            {
                ans= temp;
            }
            return;
        }
        if(dp[i][previdx+1]!=-1)
        {
            return;
        }
        if(previdx==-1 || nums[i]%nums[previdx]==0)
        {
            temp.push_back(nums[i]);
            solve(i+1,i,nums,temp,ans,dp);
            temp.pop_back();
        }
        solve(i+1,previdx,nums,temp,ans,dp);
        dp[i][previdx+1]=1;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<int>ans;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        solve(0,-1,nums,temp,ans,dp);
        return ans;
    }

*/