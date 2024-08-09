class Solution {
public:
    bool magic(vector<vector<int>>& grid, int r, int c)
    {
        //all no. are from 1 to 9 with no repeatition
        //row col dia antidia have same sum
        unordered_set<int>st;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                //checking that no. must lie in range
                int num= grid[r+i][c+j];
                if(num<1 || num>9 || st.find(num)!=st.end())
                {
                    return false;
                }
                else
                {
                    st.insert(num);
                }
            }
        }
        //rowsum to set a measure for others..
        int sum= grid[r][c]+grid[r][c+1]+grid[r][c+2];

        //diagonal checking..
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=sum)
        {
            return false;
        }
        //anti-diagonal checking..
        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=sum)
        {
            return false;
        }
            
        for(int i=0;i<3;i++)
        {
            //rowsum checking..
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!= sum)
            {
                return false;
            }
            //colsum checking..
            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=sum)
            {
                return false;
            }
        }
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size(); 
        int cnt=0;
        for(int r=0;r<=m-3;r++)
        {
            for(int c=0;c<=n-3;c++)
            {
                if(magic(grid,r,c))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};