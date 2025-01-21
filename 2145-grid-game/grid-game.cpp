class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n=grid[0].size();

        //first row sum...
        long long firstremain= accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long secondsum=0;

        //minimized robot2 sum ...
        long long ans= LONG_LONG_MAX;
        for(int col=0;col<grid[0].size();col++)
        {
            //robot1 will take this grid[0][col]..
            firstremain-= grid[0][col];

            //robot2 will try to do best after this strategy
            long long bestrobot2= max(firstremain,secondsum);
            ans= min(ans,bestrobot2);//updating so that we get minimized robot2 sum..

            secondsum+= grid[1][col];
        }
        return ans;
    }
};