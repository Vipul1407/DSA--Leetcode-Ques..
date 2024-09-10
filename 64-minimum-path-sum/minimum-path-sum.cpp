class Solution 
{
public:

    //More space optimized...
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n= grid[0].size();
        int m= grid.size();
        vector<int> curr(n+1,0);

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
                    curr[j]= grid[i][j]+ curr[j];
                }
                else
                {
                    curr[j]= grid[i][j]+ min(curr[j+1], curr[j]);
                }
            }
        }
        return curr[0];
    }
    
};

