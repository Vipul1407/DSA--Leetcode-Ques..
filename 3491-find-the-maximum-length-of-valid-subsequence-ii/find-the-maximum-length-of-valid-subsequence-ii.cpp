//this version using C-array dp
short dp[1000];
class Solution {
public:
    static int maximumLength(vector<int>& nums, int k) {
        //let dp[i] denote len for subsequence 
        short ans=0;
        for (int i=0; i<k; i++){
            fill(dp, dp+k, 0);// memset does not work well for this compiler
            for (int x : nums){
                int j=x%k;
                dp[j]=max(dp[j], short(dp[(i+k-j)%k]+1));
                ans=max(ans, dp[j]);
            }
        }
        return ans;
        
    }
};
/*
    //METHOD-1
    //BRUTE FORCE.. LIS APPROACH
    //TC= O(K*2^N).. GIving TLE..
    int LIS(int i,vector<int>& nums, int prev, int mod, int k)
    {   
        if(i>= nums.size())
        {
            return 0;
        }
        int take=0;
        int notake=0;
        if(prev==-1 || (nums[i]+nums[prev])%k==mod)
        {
            take= 1+LIS(i+1,nums,i,mod,k);
        }
        notake= LIS(i+1,nums,prev,mod,k);
        return max(take,notake);
    }
    int maximumLength(vector<int>& nums, int k) 
    {
        int ans=0;
        //prev will be -1 initially..
        //mod can go form 0 to k-1....

        for(int mod=0;mod<k;mod++)
        {
            ans= max(ans,LIS(0,nums,-1,mod,k));
        }
        return ans;
    }

    //METHOD-2
    //TDA... LIS APPROACH
    //TC= O(K*(N^2)).. GIving TLE..

    int LIS(int i,vector<int>& nums, int prev, int mod, int k, vector<vector<vector<int>>>&dp)
    {   
        if(i>= nums.size())
        {
            return 0;
        }
        int take=0;
        int notake=0;
        if(prev==-1 || (nums[i]+nums[prev])%k==mod)
        {
            take= 1+LIS(i+1,nums,i,mod,k,dp);
        }
        notake= LIS(i+1,nums,prev,mod,k,dp);
        return dp[i][prev+1][mod]= max(take,notake);
    }
    int maximumLength(vector<int>& nums, int k) 
    {
        int ans=0;
        int n= nums.size();
        //prev will be -1 initially..
        //mod can go form 0 to k-1....
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(k,-1)));
        for(int mod=0;mod<k;mod++)
        {
            ans= max(ans,LIS(0,nums,-1,mod,k,dp));
        }
        return ans;
    }
*/
