class Solution {
public:

    bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m= grid2.size();
        int n= grid2[0].size();
        //base cases..
        //if we get any out of bound indexes means we have done our computations
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return true;
        }
        //if we get any water in grid2 means we are done with our computations
        if(grid2[i][j]!=1)
        {
            return true;
        }
        grid2[i][j]=-1;//to mark it as visited block..

        bool result= (grid1[i][j]==1);// grid1 must have water there..
        result = dfs(i-1,j,grid1,grid2) && result ;//up
        result = dfs(i,j+1,grid1,grid2) && result;//right
        result = dfs(i+1,j,grid1,grid2) && result;//down
        result = dfs(i,j-1,grid1,grid2) && result;//left
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        //Note that we have to check sub-islands in grid2
        //Conditions-  
        //1)grid2 check for horizontal and vertical blocks of 1 only
        //2)grid2 wle hrr block p grid1 p bhi 1 hona chaiye agar ek bhi 0 hua to usko ni lenge
        int m= grid2.size();
        int n= grid2[0].size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1)
                {
                    if(dfs(i,j,grid1,grid2))
                    {
                        cnt++;
                    }
                    
                }
            }
        }
        return cnt;
    }
};