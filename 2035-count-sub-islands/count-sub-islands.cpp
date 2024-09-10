class Solution {
public:
    //right--> 0,1 
    //down--> 1,0
    //left--> 0,-1
    //up--> -1,0
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int m= grid2.size();
        int n= grid2[0].size();
        //USING BFS
        queue<pair<int,int>>q;
        q.push({i,j});
        grid2[i][j]=-1;//to mark it as visited

        bool result= true;
        while(!q.empty())
        {
            auto [x,y]= q.front();
            q.pop();
            //base case within queue
            if(grid1[x][y]!=1)
            {
                result= false;
            }
            for(auto i:dir)
            {
                int newx= x+ i.first;
                int newy= y+ i.second;
                if(newx>=0 && newx<m && newy>=0 && newy<n && grid2[newx][newy]==1)
                {
                    grid2[newx][newy]=-1; //to mark it as visited
                    q.push({newx,newy});
                }
            }
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int n= grid2[0].size();
        int m= grid2.size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1 && dfs(i,j,grid1,grid2))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};