class Solution {
public:
    int rec(int i,int j,vector<int>& piles, vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return piles[i];//if only one pile left then take it
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //taking minus sign as 
        //we are calculating the net advantage the current player (Alice or Bob) can achieve by picking a pile.
        int takeleft= piles[i]- rec(i+1,j,piles,dp);
        int takeright= piles[j]- rec(i,j-1,piles,dp);
        return dp[i][j]= max(takeleft,takeright);
    }
    bool stoneGame(vector<int>& piles) 
    {
        int n= piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return rec(0,n-1,piles,dp);
    }
};