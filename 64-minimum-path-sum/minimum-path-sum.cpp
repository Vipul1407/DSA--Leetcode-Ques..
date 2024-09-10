class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // Update the first row
    for (int j = 1; j < n; ++j) {
      grid[0][j] += grid[0][j - 1];
    }

    // Update the first column
    for (int i = 1; i < m; ++i) {
      grid[i][0] += grid[i - 1][0];
    }

    // Update the rest of the grid
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    }

    // Return the bottom-right corner value which is the answer
    return grid[m - 1][n - 1];
  }
};
