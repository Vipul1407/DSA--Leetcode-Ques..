class Solution {
public:
    // METHOD-1
    // BETTER APPROACH USING 2 VECTORS PREFIXMAX, SUFFIXAMX..
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);

        for (int i = 1; i < n; i++)
        {
            leftmax[i] = max(leftmax[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rightmax[i] = max(rightmax[i + 1], nums[i + 1]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            ans = max(ans, (long long)(leftmax[i] - nums[i]) * rightmax[i]);
        }
        return ans;
    }
};