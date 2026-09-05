class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf(n);                   // suf[i] = min(nums[i..n-1])
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(nums[i], suf[i + 1]);
        }

        int pre = INT_MIN;                    // running max(nums[0..i])
        for (int i = 0; i < n; i++) {
            pre = max(pre, nums[i]);
            if (pre - suf[i] <= k) return i;  // first stable index found
        }
        return -1;
    }
};