class Solution {
public:
    bool magic(vector<vector<int>>& grid, int r, int c, int k)
    {
        //row, col, diagonal, anti-diagonal must have same sum
        long long sum=0;
        for(int i=0;i<k;i++)
        {
            sum+= grid[r][c+i];
        }

        for(int i=0;i<k;i++)
        {
            long long newsum=0; 
            for(int t=0;t<k;t++)
            {
                //checking rowsum..
                newsum+= grid[r+i][c+t];
            }
            if(newsum!=sum)
            {
                return false;
            }
        }

        for(int i=0;i<k;i++)
        {
            long long newsum=0; 
            for(int t=0;t<k;t++)
            {
                //checking colsum..
                newsum+= grid[r+t][c+i];
            }
            if(newsum!=sum)
            {
                return false;
            }
        }

        long long newsum=0; 
        for(int i=0;i<k;i++)
        {
            //checking dia sum
            newsum+= grid[r+i][c+i];
        }
        if(newsum!=sum)
        {
            return false;
        }

        newsum=0; 
        for(int i=0;i<k;i++)
        {
            //checking anti-dia sum
            newsum+= grid[r+i][c+(k-1-i)];
        }
        if(newsum!=sum)
        {
            return false;
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        int k= min(n,m);//to be a square matrix
        for(int k=1;k<=min(n,m);k++)
        {
            for(int r=0;r<=m-k;r++)
            {
                for(int c=0;c<=n-k;c++)
                {
                    if(magic(grid,r,c,k))
                    {
                        ans= max(ans,k);
                    }
                }
            }
        }
        return ans;
    }
};