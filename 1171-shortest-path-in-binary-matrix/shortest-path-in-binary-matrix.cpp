class Solution {
public:
    vector<int>dx={0,1,1,1,0,-1,-1,-1};
    vector<int>dy={1,1,0,-1,-1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
         int m= grid.size();
        int n= grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1)
        {
            return -1;
        }
       
        queue<pair<pair<int,int>,int>  >q;
        q.push({{0,0},1});
        grid[0][0]= 1;
        int ans= INT_MAX;
        while(q.size())
        {
            int i= q.front().first.first;
            int j= q.front().first.second;
            int steps= q.front().second;
            q.pop();

            if(i==m-1 && j==n-1)
            {
                ans= min(ans,steps);
            }
        
            for(int k=0;k<8;k++)
            {
                int x= i+dx[k];
                int y= j+dy[k];
                if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==1)
                {
                    continue;
                }
                q.push({{x,y},steps+1});
                grid[x][y]=1;
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};