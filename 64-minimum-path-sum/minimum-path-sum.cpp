class Solution 
{
public:

    //It is only dependent on-:
    //dp[i+1][j]--> next row
    //dp[i][j+1]--> curr row
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n= grid[0].size();
        int m= grid.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1)
                {
                    curr[j]= grid[i][j]+ curr[j+1];
                }
                else if(j==n-1)
                {
                    curr[j]= grid[i][j]+ next[j];
                }
                else
                {
                    curr[j]= grid[i][j]+ min(curr[j+1], next[j]);
                }
            }
            swap(curr,next);
        }
        return next[0];
    }
    
};

