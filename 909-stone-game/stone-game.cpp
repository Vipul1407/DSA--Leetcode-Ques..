class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int n= piles.size();
        vector<int>next(n,-1);
        // if(i==j)
        // {
        //     return piles[i];//if only one pile left then take it
        // }
        for(int i=0;i<n;i++)
        {
            next[i]= piles[i];
        }
        //starting from 2nd row..
        for(int i=n-2;i>=0;i--)
        {
            vector<int>curr(n,0);
            //starting from 2nd row..
            for(int j=i+1;j<n;j++)
            {
                int left= piles[i]- next[j];
                int right= piles[j]- curr[j-1];
                curr[j]= max(left,right);
            }
            next=curr;
        }
        return next[n-1];
    }
};

/*
// Alice/bob can take either last/first element..
// GREEDY WILL FAIL for eg.-
//  arr=[5,4,100,9]
// acc. to greedy
// A takes 9 --> arr=[5,4,100]
// B takes 100 --> arr=[5,4]
// A takes 5
// B takes 4
// B wins...
// but we have to play such that A must win
// Hence, we will use DP here...

// METHOD-1
// RECURSIVE
int rec(int i, int j, vector<int> &piles)
{
    if (i == j)
    {
        return piles[i]; // if only one pile left then take it
    }
    // taking minus sign as
    // we are calculating the net advantage the current player (Alice or Bob) can achieve by picking a pile.
    int takeleft = piles[i] - rec(i + 1, j, piles);
    int takeright = piles[j] - rec(i, j - 1, piles);
    return max(takeleft, takeright);
}
bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    return rec(0, n - 1, piles);
}

// METHOD-2
// TDA
// BEATS 19%
int rec(int i, int j, vector<int> &piles, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return piles[i]; // if only one pile left then take it
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // taking minus sign as
    // we are calculating the net advantage the current player (Alice or Bob) can achieve by picking a pile.
    int takeleft = piles[i] - rec(i + 1, j, piles, dp);
    int takeright = piles[j] - rec(i, j - 1, piles, dp);
    return dp[i][j] = max(takeleft, takeright);
}
bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return rec(0, n - 1, piles, dp);
}

//METHOD-3
// BUA
// BEATS 33%
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
        // starting from 2nd row..
        for (int j = 1; j < n; j++)
        {
            int left = piles[i] - dp[i + 1][j];
            int right = piles[j] - dp[i][j - 1];
            dp[i][j] = max(left, right);
        }
    }
    return dp[n - 1][0];
}
*/