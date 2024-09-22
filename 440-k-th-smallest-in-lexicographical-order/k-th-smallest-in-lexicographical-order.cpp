class Solution {
public:

    int Count(int n, long curr, long next) {
        int count = 0;
        while (curr <= n) {
            count += next - curr;
            curr *= 10;
            next *= 10;
            next = min((long)(n + 1), next);
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;  // Start with the first number lexicographically
        k--;  // Since we start from the first, we need k-1 more steps

        while (k > 0) {
            int step = Count(n, curr, curr + 1);  // Count # between `curr` and the next lexicographical number
            if (step <= k) {
                // If there are fewer or equal steps than `k`, we can skip this subtree and go to the next sibling
                curr++;
                k -= step;
            } else {
                // Otherwise, we need to go deeper into the current subtree
                curr *= 10;
                k--;  // We're using the current number, so decrement `k`
            }
        }

        return curr;
    }
};