class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        // DP table to store maximum points at each cell
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Initialize the first row of DP table
        for (int c = 0; c < n; ++c) {
            dp[0][c] = points[0][c];
        }
        
        // Iterate through each row starting from the second row
        for (int r = 1; r < m; ++r) {
            // Compute left and right maximums for each column
            vector<long long> left(n, 0);
            vector<long long> right(n, 0);

            left[0] = dp[r-1][0];
            for (int c = 1; c < n; ++c) {
                left[c] = max(left[c-1], dp[r-1][c] + c);
            }

            right[n-1] = dp[r-1][n-1] - (n-1);
            for (int c = n-2; c >= 0; --c) {
                right[c] = max(right[c+1], dp[r-1][c] - c);
            }

            // Update DP table for the current row
            for (int c = 0; c < n; ++c) {
                dp[r][c] = points[r][c] + max(left[c] - c, right[c] + c);
            }
        }

        // The result is the maximum value in the last row of the DP table
        return *max_element(dp[m-1].begin(), dp[m-1].end());
    }
};