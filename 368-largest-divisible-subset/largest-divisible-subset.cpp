class Solution {
public:
    //METHOD-1
    //1D LIS Approach..
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int LISidx=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++)
        {
            for(int previdx=0;previdx<i;previdx++)
            {
                if(nums[i]%nums[previdx]==0)
                {
                   if(dp[i]< 1+dp[previdx])
                   {
                        dp[i]= 1+dp[previdx];
                        parent[i]= previdx;
                   }
                }
            }
            if(dp[i]>dp[LISidx])
            {
                LISidx= i;
            }
        }
        vector<int>ans;
        while(LISidx!=-1)
        {
            ans.push_back(nums[LISidx]);
            LISidx= parent[LISidx];
        }
        return ans;
    }
};
/*
    //METHOD-2
    //Recursive backtracking Approach..
    //TLE...
    //TC= O(2^n)
    void tda(int i, int prev, vector<int>&temp, vector<int>&ans, vector<int>& nums)
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
            tda(i+1,nums[i],temp,ans,nums);
            temp.pop_back();//backtracking..
        }
        tda(i+1,prev,temp,ans,nums);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n= nums.size();
        sort(begin(nums),end(nums));
        vector<int>ans,temp;
        tda(0,-1,temp,ans,nums);
        return ans;
    }
    
*/