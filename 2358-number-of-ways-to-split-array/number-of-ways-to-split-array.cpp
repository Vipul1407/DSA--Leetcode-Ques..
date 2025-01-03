class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        int n= nums.size();
        vector<long long>rminusl(n,0);
        rminusl[0]= nums[0];
        for(int i=1;i<n;i++)
        {
            rminusl[i]= rminusl[i-1]+nums[i];
        }
        long long sum= nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rminusl[i]-=sum;
            sum+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(rminusl[i]>=0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
/*
// METHOD-1
// TAKING 2 VECTORS..
// BEATS 8%
int waysToSplitArray(vector<int> &nums)
{
    int n = nums.size();
    vector<long long> leftsum(n, 0);
    vector<long long> rightsum(n, 0);
    leftsum[0] = nums[0];
    rightsum[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftsum[i] = leftsum[i - 1] + nums[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightsum[i] = rightsum[i + 1] + nums[i];
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (leftsum[i] >= rightsum[i + 1])
        {
            cnt++;
        }
    }
    return cnt;
} 
*/