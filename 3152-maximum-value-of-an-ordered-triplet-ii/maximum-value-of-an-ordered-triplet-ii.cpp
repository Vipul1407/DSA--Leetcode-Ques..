class Solution {
public:
    // METHOD-2
    // BETTER APPROACH USING 1 VECTOR ONLY..
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        vector<int> rightmax(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            rightmax[i] = max(rightmax[i + 1], nums[i + 1]);
        }
        int leftmax = 0;
        for (int i = 1; i < n - 1; i++)
        {
            leftmax = max(leftmax, nums[i - 1]);
            ans = max(ans, (long long)(leftmax - nums[i]) * rightmax[i]);
        }
        return ans;
    }
};