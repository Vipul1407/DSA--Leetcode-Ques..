class Solution {
public:
    //METHOD-3
    //SLIDING WINDOW..
    //TC= O(N)
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=1;
        int i=0,j=0;
        int mask=0;
        while(j<n)
        {
            //shrink window..
            while((mask & nums[j])!=0)
            {
                //do xor to remove that element from window..
                mask^= nums[i];
                i++;
            }
            ans= max(ans,j-i+1);
            mask |= nums[j];
            j++;
        }
        return ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
// TC= O(N^3)
bool nice(int i, int j, vector<int> &nums)
{
    int mask = 0;
    for (int k = i; k <= j; k++)
    {
        if (mask & nums[k] != 0)
        {
            return false;
        }
        mask |= nums[k];
    }
    return true;
}
int longestNiceSubarray(vector<int> &nums)
{
    int n = nums.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (nice(i, j, nums))
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

// METHOD-2
// BETTER APPROACH..
// TC= O(N^2)
int longestNiceSubarray(vector<int> &nums)
{
    int n = nums.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = i; j < n; j++)
        {
            if (mask & nums[j] != 0)
            {
                break;
            }
            else
            {
                ans = max(ans, j - i + 1);
            }
            mask |= nums[j];
        }
    }
    return ans;
}
*/