class Solution {
public:
    int solve(int i, vector<vector<int>>& books, int sw, vector<int>&dp)
    {
        if(i>=books.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int w=0;
        int maxht=0;
        int ans= INT_MAX;
        int n= books.size();
        for(int j=i;j<n;j++)
        {
            w+= books[j][0];
            if(w>sw)
            {
                break;
            }
            maxht= max(maxht, books[j][1]); 
            ans= min(ans, maxht+ solve(j+1,books,sw,dp));
        }
        return dp[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) 
    {
        vector<int>dp(books.size()+1,-1);
        return solve(0,books,sw,dp);
    }
};