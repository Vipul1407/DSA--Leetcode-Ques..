class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int rowmin=m,rowmax=0;
        int colmin=n,colmax=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    rowmin=min(rowmin,i);
                    colmin= min(colmin,j);
                    rowmax= max(rowmax,i);
                    colmax= max(colmax,j);
                }
            }
        }
        return (rowmax-rowmin+1)*(colmax-colmin+1);
    }
};