class Solution {
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // if(i==j)
        // {
        //     return piles[i];//if only one pile left then take it
        // }
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i];
        }
        // starting from 2nd row..
        for (int i = n - 2; i >= 0; i--)
        {
            // starting from i+1 row..
            for (int j = i+1; j < n; j++)
            {
                int left = piles[i] - dp[i + 1][j];
                int right = piles[j] - dp[i][j - 1];
                dp[i][j] = max(left, right);
            }
        }
        return dp[n - 1][0];
    }
};