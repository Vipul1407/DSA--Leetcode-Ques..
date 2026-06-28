//translated using AI
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1, 0);

        for (int x : arr) {
            cnt[min(x, n)]++;
        }

        int val = 0;

        for (int i = 1; i <= n; i++) {
            val = min(i, val + cnt[i]);
        }

        return val;
    }
};