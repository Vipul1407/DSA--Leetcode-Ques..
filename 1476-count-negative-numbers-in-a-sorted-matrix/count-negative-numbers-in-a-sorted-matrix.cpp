class Solution {
public:
    //METHOD-3
    //SEARCH IN ROTATED SORTED ARRAY METHOD..
    ///TC= O(M+N)
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        int row= m-1;
        int col=0;
        while(row>=0 && col<n)
        {
            //we found the 1st -ve in current row..
            //skip row==> row--;
            if(grid[row][col]<0)
            {
                ans+= n-col;
                row--;
            }
            else
            {
                col++;
            }
        }
        return ans;
    }
};
/*
    //METHOD-2
    //BINARY SEARCH..
    ///TC= O(M* LOGN)
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int n= grid[0].size();
            int l= 0;
            int r= n-1;
            int neg= n;
            //binary search..
            while(l<=r)
            {
                int mid= l+(r-l)/2;
                //since it is sorted in decreasing order..
                if(grid[i][mid]<0)
                {
                    neg= mid;
                    r= mid-1;
                }
                else
                {
                    l= mid+1;
                }
            }
            ans+= n-neg;
        }
        return ans;
    }
*/