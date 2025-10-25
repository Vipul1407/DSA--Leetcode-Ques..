class Solution {
public:
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