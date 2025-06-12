class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int n= nums.size();
        int ans= INT_MIN;
        for(int i=1;i<=n;i++)
        {
             ans= max(ans, abs(nums[i%n]-nums[(i-1)%n]));
        }
        return ans;
    }
};