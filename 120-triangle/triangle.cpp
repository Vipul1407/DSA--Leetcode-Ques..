class Solution {
public:
    int tda(int i,int j,vector<vector<int>>& tri,vector<vector<int>>&dp)
    {
        //last row then return the value..
        //no need to handle for j as j max go to i+1 i.e 0<=j<=i
        if(i==tri.size()-1)
        {
            return tri[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //down,diagonal
        return dp[i][j]= tri[i][j]+ min(tda(i+1,j,tri,dp),tda(i+1,j+1,tri,dp));
    }
    int minimumTotal(vector<vector<int>>& tri) 
    {
        int n= tri.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return tda(0,0,tri,dp);
    }
};