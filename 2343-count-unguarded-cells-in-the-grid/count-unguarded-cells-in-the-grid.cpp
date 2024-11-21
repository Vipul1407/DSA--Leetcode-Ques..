class Solution {
public:
    //function to mark it as visited...
    void solve(int i,int j,vector<vector<int>>& vis)
    {
        int m= vis.size();
        int n= vis[0].size();
        //right...
        for(int col=j+1;col<n;col++)
        {
            //agar cell pe guard aae ya wall h to break kr ja
            if(vis[i][col]==2 || vis[i][col]==3)
            {
                break;
            }
            vis[i][col]=1;//mark as visited..
        }
        //down...
        for(int row=i+1;row<m;row++)
        {
            //agar cell pe guard aae ya wall h to break kr ja
            if(vis[row][j]==2 || vis[row][j]==3)
            {
                break;
            }
            vis[row][j]=1;//mark as visited..
        }
        //left...
        for(int col=j-1;col>=0;col--)
        {
            //agar cell pe guard aae ya wall h to break kr ja
            if(vis[i][col]==2 || vis[i][col]==3)
            {
                break;
            }
            vis[i][col]=1;//mark as visited..
        }
        //up...
        for(int row=i-1;row>=0;row--)
        {
            //agar cell pe guard aae ya wall h to break kr ja
            if(vis[row][j]==2 || vis[row][j]==3)
            {
                break;
            }
            vis[row][j]=1;//mark as visited..
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        //0 represent unvisited
        //1 represent visited
        //2 represent guard
        //3 represent wall
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(auto i:walls)
        {
            vis[i[0]][i[1]]= 3;
        }
        for(auto i:guards)
        {
            vis[i[0]][i[1]]= 2;
        }
        //jha guard ki pahuch h usko mark kr visited...
        for(auto g:guards)
        {
            solve(g[0],g[1],vis);
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};