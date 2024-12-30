class Solution {
public:
    //TOP-DOWN APPRAOCH..
    int help(vector<int>&subarray,int i,int cnt,int &k,vector<vector<int>>&dp)
    {
        //helping to decide whether which one is giving max ans==> take or notake..
        if(cnt==0)
        {
            return 0;
        }
        //Denoting invalid case...
        if(i>=subarray.size())
        {
            return INT_MIN;
        }
        if(dp[i][cnt]!=-1)
        {
            return dp[i][cnt];
        }
        int take= subarray[i]+ help(subarray,i+k,cnt-1,k,dp);
        int notake= help(subarray,i+1,cnt,k,dp);
        return dp[i][cnt]= max(take,notake);
    }
    void solve(vector<int>&subarray,int i,int cnt,int &k,vector<int>&res, vector<vector<int>>&dp)
    {
        if(cnt==0)
        {
            return;
        }
        if(i>=subarray.size())
        {
            return;
        }
        int take= subarray[i]+ help(subarray,i+k,cnt-1,k,dp);
        int notake= help(subarray,i+1,cnt,k,dp);
        //take case..
        //taking also in = case as we want lexicographically smallest index..
        if(take>=notake)
        {
            res.push_back(i);
            solve(subarray,i+k,cnt-1,k,res,dp);
        }
        //notake case..
        else
        {
            solve(subarray,i+1,cnt,k,res,dp);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<int>subarray;
        int i=0,j=0;
        int sum=0;
        while(j<n)
        {
            sum+= nums[j];
            if(j-i+1==k)
            {
                subarray.push_back(sum);
                sum-= nums[i];
                i++;
            }
            j++;
        }
        vector<int>res;
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        //3 is the cnt as we have to find 3 subarrays as given in ques always...
        //0 is the starting index of the subarrayy...
        solve(subarray,0,3,k,res,dp);
        return res;
    }
};
/*
// METHOD-1
// RECURSIVE..
int help(vector<int> &subarray, int i, int cnt, int &k)
{
    // helping to decide whether which one is giving max ans==> take or notake..
    if (cnt == 0)
    {
        return 0;
    }
    // Denoting invalid case...
    if (i >= subarray.size())
    {
        return INT_MIN;
    }
    int take = subarray[i] + help(subarray, i + k, cnt - 1, k);
    int notake = help(subarray, i + 1, cnt, k);
    return max(take, notake);
}
void solve(vector<int> &subarray, int i, int cnt, int &k, vector<int> &res)
{
    if (cnt == 0)
    {
        return;
    }
    if (i >= subarray.size())
    {
        return;
    }
    int take = subarray[i] + help(subarray, i + k, cnt - 1, k);
    int notake = help(subarray, i + 1, cnt, k);
    // take case..
    // taking also in = case as we want lexicographically smallest index..
    if (take >= notake)
    {
        res.push_back(i);
        solve(subarray, i + k, cnt - 1, k, res);
    }
    // notake case..
    else
    {
        solve(subarray, i + 1, cnt, k, res);
    }
}
vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> subarray;
    int i = 0, j = 0;
    int sum = 0;
    while (j < n)
    {
        sum += nums[j];
        if (j - i + 1 == k)
        {
            subarray.push_back(sum);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    vector<int> res;
    // 3 is the cnt as we have to find 3 subarrays as given in ques always...
    // 0 is the starting index of the subarrayy...
    solve(subarray, 0, 3, k, res);
    return res;
}
*/